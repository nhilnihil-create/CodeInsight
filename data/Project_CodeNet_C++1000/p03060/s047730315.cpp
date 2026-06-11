#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll N;
    string S; 
    cin >> N;
    vector <int> V(N+2), C(N+2),D(N+2);
    for(int i=0; i<N; i++){
        cin >> V[i];
    }
    for(int i=0; i<N; i++){
        cin >> C[i];
        D[i] = V[i] - C[i];
    }
    sort(D.begin(),D.end(),greater<int>());
    int k = 0,ans=0;
    while( D[k] >= 0 && k != N){
        ans += D[k];
        k++;
    }
    cout << ans << endl;
}