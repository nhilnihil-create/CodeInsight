#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin >> n;
    int k;
    cin >> k;
    int cost[n];
    int h;
    for(int i=0;i<n;i++){
        cin >> h;
        cost[i] = h;
    }

    int min_cost[n];
    min_cost[0] = 0;
    min_cost[1] = abs(cost[0]-cost[1]);

    for(int i=2;i<n;i++){
        int mini = abs(cost[i-1]-cost[i]) + min_cost[i-1];
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                mini = min(mini,abs(cost[i-j]-cost[i]) + min_cost[i-j]);
            }
        }
        min_cost[i] = mini;
    }

    cout << min_cost[n-1] << endl;

    return 0;
}

