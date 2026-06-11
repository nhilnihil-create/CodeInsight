#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int x,y,z;
    int ans = 0;
    x = n/r + 1;
    y = n/g + 1;
    rep(i,x){
        rep(j,y){
            int res = n - i * r - j * g;
            if(res >= 0 && res % b == 0) ans++; 
        }
    }
    cout << ans << endl;
}