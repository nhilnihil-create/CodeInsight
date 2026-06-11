#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n;
    cin >> n;
    int ans = 0;

    while(n >= 3){
        n -= 3;
        ans++;
    }

    cout << ans << endl;

    return 0;
}