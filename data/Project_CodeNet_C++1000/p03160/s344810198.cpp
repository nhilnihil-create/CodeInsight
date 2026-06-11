#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> DP(n, 0);
    int height [n];

    for (int i=0; i<n; i++) {
        cin>>height[i];
    }

    DP[1]=abs(height[1]-height[0]);

    for (int i=2;i<n;i++){
        DP[i] = min(abs(height[i]-height[i-1]) + DP[i-1], abs(height[i]-height[i - 2])+DP[i-2]);
    }

    cout<<DP[n-1];
}
