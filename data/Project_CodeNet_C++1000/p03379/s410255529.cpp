#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
    int N;
    cin>>N;
    vector<int>X(N);
    rep(i,N){
        cin>>X[i];
    }
  	vector<int>Y(N);
  rep(i,N){
    Y[i]=X[i];
  }
  	sort(X.begin(),X.end());
        int mi=X[N/2-1];
        int ma=X[N/2];
        rep(i,N){
            if(ma<=Y[i]){
                cout<<mi<<endl;
            }
            else{
                cout<<ma<<endl;
            }
        }
    }
