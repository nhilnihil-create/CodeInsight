#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)

int main() {
    ll n,y;
    cin >> n >> y;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int k = n - i - j;
            if(k<0||k>n)continue;
            if(10000*i+5000*j+1000*k != y) continue;
            cout << i << " " << j << " " << k << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}