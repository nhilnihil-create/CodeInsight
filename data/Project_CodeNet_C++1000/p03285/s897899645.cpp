#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i = 0; i <= n; i += 4){
        for (int j = 0; j <= n; j += 7){
            if (i+j == n){cout << "Yes" << endl;return 0;}
        }
    }
    cout << "No" << endl;
    return 0;
}