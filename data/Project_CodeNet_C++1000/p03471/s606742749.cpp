#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {

    ll n,y; cin >> n >> y;
    vector<ll> x(3,-1);
    y /= 1000;

    for(int i = 0; i <=n; i ++){
        for(int j = 0; j <= n-i; j ++){
            if(10*i + 5*j + 1*(n-j-i) == y){
                x[0] = i;
                x[1] = j;
                x[2] = n-j-i;
            }
        }
        if(x[0] != -1) break;
    }

    cout << x[0] << " " << x[1] << " " << x[2];

    return 0;
}









