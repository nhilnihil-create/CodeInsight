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
    ll N;
    cin>>N;
    vector< pair<ll, ll> > A, B, Asur, Bsur;
    ll a, b;
    vector< pair<bool, ll> > se;
    rep(i, N) cin>>a>>b, A.push_back({a, i}),B.push_back({b, i});
    rep(i, N){
        Asur.push_back({A[i].first+B[i].first, i});
        Bsur.push_back({B[i].first+A[i].first, i});
        se.push_back({false, i});
    }
    sort(all(Asur));
    sort(all(Bsur));
    ll anum=N-1, bnum=N-1;
    ll asum=0, bsum=0;
    rep(i, N){
        if(i%2==0){
            while(se[Asur[anum].second].first) anum--;
            asum+=A[Asur[anum].second].first;
            se[Asur[anum].second].first=true;
        }
        if(i%2!=0){
            while(se[Bsur[bnum].second].first) bnum--;
            bsum+=B[Bsur[bnum].second].first;
            se[Bsur[bnum].second].first=true;
        }
        //cout<<asum<<sp<<bsum<<endl;
    }
    cout<<asum-bsum<<endl;
    return 0;
}
