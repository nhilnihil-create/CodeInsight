#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, h[100100], cost[100200]={0}, k, i;
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> h[i];
    }

    for(i=1;i<n;i++){
        cost[i]=cost[i-1]+abs(h[i-1]-h[i]);
        for(int j=2;j<=k;j++){
            if(i-j<0) break;
            cost[i]=min(cost[i], cost[i-j]+abs(h[i-j]-h[i]));
        }
    }

    cout << cost[n-1] <<endl;
    return 0;
}
