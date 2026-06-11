#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)


int main() {
    int N;
    cin>>N;
    vector<ld>X(N);
    vector<string>Y(N);
    ld ans=0;
    rep(i,N){
        cin>>X[i];
        cin>>Y[i];
        if(Y[i]=="JPY"){
            ans+=X[i];
        }
        else{
            ans+=X[i]*380000.0;
        }
    }
    cout<<ans<<endl;
}
