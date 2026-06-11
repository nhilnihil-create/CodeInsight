#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int N;
    cin>>N;
    vector<int>P(N);
    int ans=0;
    int ma=0;
    rep(i,N){
        cin>>P[i];
        ans+=P[i];
         if(ma<P[i]){
            ma=P[i];
        }
    }
    cout<<ans-ma/2<<endl;
}