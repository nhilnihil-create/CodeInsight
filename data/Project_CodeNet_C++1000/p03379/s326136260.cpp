#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long N;
    cin>>N;
    long X[N];
    long Y[N];
    rep(i, N){
        cin>>X[i];
        Y[i] = X[i];
    }

    long middle = N/2-1;
    sort(Y, Y+N);
    rep(i, N){
        if(X[i] <= Y[middle]) cout << Y[middle+1] << endl;
        else cout << Y[middle] << endl;
    }
}
