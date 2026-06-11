#include <bits/stdc++.h>
using namespace std;

int main(){
    double n,k;
    cin >> n >> k;
    vector<int> t(n);
    int c = 0;

    for (int i = n; i >= 1; i--){
        int s = i;
        while (s * pow(2, c) < k){
            c++;
        }
        t[i-1] = c;
    }

    double ans = 0;
    if (k != 1){
        for (int i = 0; i < n; i++){
            ans += 1/n * pow(0.5, t[i]);
        }
        cout << fixed << setprecision(12);
        cout << ans << endl;
    }
    else{
        cout << 1 << endl;
    }
    
}