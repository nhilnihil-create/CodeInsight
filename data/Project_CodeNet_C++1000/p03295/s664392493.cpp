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
    ll N, M;
    ll a, b, ma[200000];
    cin>>N>>M;
    MEMSET(ma, 0);
    rep(i, M){
        cin>>a>>b;
        ma[b]=max(a, ma[b]);
    }
    ll cutpoint=0, cutcount=0;
    rep1(i, N){
        if(cutpoint<ma[i]){
            cutcount++;
            cutpoint=i-1;
        }
    }
    cout<<cutcount<<endl;
    return 0;
}
