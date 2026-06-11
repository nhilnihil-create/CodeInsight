#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,y;
    cin >> n >> y;
    y/=1000;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(n-i-j>=0 && 10*i+5*j+n-i-j==y){
                cout << i << ' ' << j << ' ' << n-i-j << endl;
                return 0;
            }
        }
    }
    cout <<"-1 -1 -1" << endl;


    return 0;
}