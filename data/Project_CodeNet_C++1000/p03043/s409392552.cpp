#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long N,K; cin>>N>>K;
    
    double sum = 0;
    rep(i, N){
        long s = i+1;
        int j=0;
        while(s < K){
            s *= 2;
            j++;
        }
        sum += 1.0/N * pow(0.5, j);
    }

    cout << fixed << setprecision(10) <<sum << endl;
}
