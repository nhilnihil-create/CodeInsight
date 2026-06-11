#include <bits/stdc++.h>
//#include <stdlib.h>
using namespace std;

int main (){
    int n;
    cin >> n;
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
        min_cost[i] = min(abs(cost[i]-cost[i-2])+min_cost[i-2],abs(cost[i]-cost[i-1])+min_cost[i-1]);
    }

    cout << min_cost[n-1] << endl;

    return 0;
}
