#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    int n, k; cin >> n >> k;

    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    vector<int>cost(n, INT_MAX);
    cost[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        for(int j = i+1; j <= i+k && j < n; j++){
            cost[i] = min(cost[i], cost[j]+abs(v[j]-v[i]));
        }
    }

    cout<<cost[0]<<endl;
}
