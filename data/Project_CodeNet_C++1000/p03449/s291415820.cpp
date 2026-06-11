#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    int ans = 0;
    vector<int> memo(n);
    memo[0] = a[0][0];
    for(int i = 1; i < n; i++){
        memo[i] = memo[i-1]+a[0][i];
    }
    for(int i = 0; i < n; i++){
        int coans = memo[i];
        for(int j = i; j < n; j++) coans += a[1][j];
        if(ans < coans) ans = coans;
    }
    cout << ans << endl;
    return 0;
}