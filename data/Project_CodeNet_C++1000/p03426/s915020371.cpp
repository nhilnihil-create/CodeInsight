#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll H, W, D;
    cin>>H>>W>>D;
    ll zahyo[100000][2];
    ll cost[100000];
    ll A;
    rep(i, H) rep(j, W){
        cin>>A;
        zahyo[A-1][0]=i;
        zahyo[A-1][1]=j;
    }
    rep(i, D){
        ll site=i;
        cost[site]=0;
        site+=D;
        while(site<=H*W){
            cost[site]=cost[site-D]+abs(zahyo[site][0]-zahyo[site-D][0])+abs(zahyo[site][1]-zahyo[site-D][1]);
            site+=D;
        }
    }
    ll Q;
    cin>>Q;
    ll L, R;
    ll count=0;
    rep(i, Q){
        cin>>L>>R;
        cout<<cost[R-1]-cost[L-1]<<endl;
    }
    return 0;
}
