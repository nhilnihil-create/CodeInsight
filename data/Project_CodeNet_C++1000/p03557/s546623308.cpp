#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n , x[3][100000] , y[2][100000] , nasu;
    long long ans = 0;

    cin >> n;
    for(int i=0 ;i<3 ;i++ ){
        for(int j=0 ;j<n ;j++){
            cin >> x[i][j]; 
        }

        sort(x[i] , x[i] + n);
    }

    nasu = 0;
    for(int i=0 ;i<n ;i++ ){
        if(i > 0){
            y[0][i] = y[0][i-1];
        } else {
            y[0][0] = 0;
        }

        while(x[1][i] > x[0][nasu] && nasu < n){
            y[0][i]++;
            nasu++;
        }
    }

    nasu = n-1;
    for(int i=n-1; i>=0 ;i-- ){
        if(i < n-1){
            y[1][i] = y[1][i+1];
        } else {
            y[1][0] = 0;
        }

        while(x[1][i] < x[2][nasu] && nasu >= 0){
            y[1][i]++;
            nasu--;
        }
    }

    for(int i=0 ;i<n ;i++ ){
        ans += (long long) y[1][i] * y[0][i];
    }

    cout << ans << endl;

    return (0);
}