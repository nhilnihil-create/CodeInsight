#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A.at(i);
        }
        ll maximam=A.at(0);
        ll minimam=A.at(0);
        
        rep(i,N){
            maximam=max(A.at(i),maximam);
            minimam=min(A.at(i),minimam);
        }
        cout << maximam-minimam << endl;
    
}