#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int x = -1,y = -1,z = -1;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            int k = n - i - j;
            if(k >= 0 && 10000*i + 5000*j + 1000*k == m){
                x = i; y = j; z = k;
                break;
            }
        }
    }
    cout << x << " " << y << " " << z << endl;
}