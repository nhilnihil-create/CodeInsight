#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int R,G,B,N; cin>>R>>G>>B>>N;

    ll ans=0;
    for(int r=0; r*R<=N; r++){
        for(int g=0; g*G<=N; g++){
            int b = N - r*R -g*G;
            if(b<0) break;
            if(b%B==0) ans++;
            // cerr << r << " " << g << " " << b <<endl;
        }
    }
    cout << ans << endl;
}
