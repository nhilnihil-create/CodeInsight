#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    double ret = 0;
    for (int i = 1; i <= n; i++){
        double tmp = 1.0 / n;
        int now = i;
        while (now < k){
            now *= 2;
            tmp /= 2;
        }
    ret += tmp;
    }
    cout << fixed << setprecision(15) << ret << endl;
}
