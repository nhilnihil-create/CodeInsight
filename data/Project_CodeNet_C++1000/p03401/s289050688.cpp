#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+2);
    a[0] = 0;
    a[n+1] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int sum = 0;
    for(int i = 1; i <= n+1; i++){
        sum += abs(a[i]-a[i-1]);
    }
    for(int i = 1; i <= n; i++){
        int ans = sum;
        ans -= abs(a[i]-a[i-1]);
        ans -= abs(a[i]-a[i+1]);
        ans += abs(a[i-1]-a[i+1]);
        cout << ans << endl;
    }
    return 0;
}