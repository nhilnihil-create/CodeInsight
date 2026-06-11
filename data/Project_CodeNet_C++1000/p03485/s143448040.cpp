#include <bits/stdc++.h>
using namespace std;

int main() {
    float a,b;
    int ans;
    cin >> a >> b;
    for (int m = 0;m<=100;m++) {
        if (a+b > 2*(m-1) && 2*m >= a+b){
            ans = m;
        }
    }
    cout << ans << endl;
}
