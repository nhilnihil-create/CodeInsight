#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;

    for(int x = 0; x <= n; ++x){
        for(int y = 0; y <= n - x; ++y){
            int z = n - x - y;
            if(10000 * x + 5000 * y + 1000 * z == s){
                cout << x << " "<< y << " " << z << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}