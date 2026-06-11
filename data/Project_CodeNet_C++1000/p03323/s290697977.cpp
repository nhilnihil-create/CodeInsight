#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    string ans = ":(";
    cin >> a >> b;
    
    if (a <= 8 && b <= 8) {
        ans = "Yay!";
    }
    
    cout << ans << endl;
}
