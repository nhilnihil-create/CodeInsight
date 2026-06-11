#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    int n; cin >> n;

    vector<long long>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    vector<int>cost(n);
    cost[n-1] = 0;
    cost[n-2] = abs(v[n-1]-v[n-2]);
    for(int i = n-3; i >= 0; i--){
        cost[i] = min(abs(v[i]-v[i+1])+cost[i+1], abs(v[i]-v[i+2])+cost[i+2]);
    }

    cout<<cost[0]<<endl;
}
