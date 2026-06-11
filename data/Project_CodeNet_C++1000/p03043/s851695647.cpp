#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    double ans = 0;
    for(int j = 1; j<=n; j++){
        double add = 1.0/n;
        int i = j;
        while(i < k){
            i *= 2;
            add /= 2;
        }
        ans += add;
    }
    cout << std::fixed << std::setprecision(10) << ans << endl;
}
