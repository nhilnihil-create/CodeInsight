#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
int main() {
    int n ;
    cin >> n;
    double arr[n];
    for(int i =0 ; i< n; i ++){
        cin >> arr[i];
    }
    double dd[n + 1][n + 1];
    memset(dd , 0 , sizeof dd);
    dd[0][1] = arr[0];
    dd[0][0] = 1 - arr[0];
    for(int i = 1 ;i < n; i ++){
        for(int j = 0; j <= n ;j ++){
            if(j == 0){
                dd[i][j] = dd[i-1][j]*(1 -arr[i]);
            }else
            dd[i][j] = dd[i-1][j]*(1 - arr[i]) + dd[i-1][j-1] * arr[i];
        }
    }
    double ans = 0;
    for(int i = n / 2 + 1 ; i <= n; i++){
        ans += dd[n - 1][i];
    }
    cout << fixed << setprecision(9) << ans;
}
