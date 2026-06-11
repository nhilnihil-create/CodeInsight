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
    cin>>N>>K;
    ll V[100];
    rep(i, N) cin>>V[i];
    ll Maxim=0;
    rep(i, K+1) rep(j, K+1-i){
        if(i+j>N) continue;
        ll count=0;
        vector<ll> je;
        //cout<<i<<sp<<j<<endl;
        rep(k, i) je.push_back(V[k]);
        rep(k, j) je.push_back(V[N-1-k]);
        sort(all(je));
        rep(k, K-i-j){
            if(k<je.size()) if(je[k]<0) je[k]=0;
        }
        rep(i, je.size()){
            count+=je[i];
        }
        Maxim=max(Maxim, count);
    }
    cout<<Maxim<<endl;
    return 0;
}
