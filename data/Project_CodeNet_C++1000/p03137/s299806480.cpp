#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long N,M;
    cin>>N>>M;
    long X[M];
    rep(i, M) cin>>X[i];

    sort(X, X+M);
    if(N >= M){
        cout << 0 << endl;
        return 0;
    }
    vector<long> dis;
    long sum = 0;
    rep(i, M-1){
        dis.push_back(abs(X[i+1]-X[i]));
        sum += dis[i];
    }

    sort(dis.rbegin(), dis.rend());
    rep(i, N-1){
        sum -= dis[i];
    }

    cout << sum << endl;
}
