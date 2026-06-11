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
    ll N, K;
    ll H;
    vector<ll> h, sur;
    cin>>N>>K;
    rep(i, N){
        cin>>H;
        h.push_back(H);
    }
    ll Minim=9999999999;
    sort(all(h));
    rep(i, N-K+1){
        Minim=min(h[i+K-1]-h[i], Minim);
    }
    cout<<Minim<<endl;
    return 0;
}
