#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for(int i = 0;i < n/r+1;i++){
        for(int j = 0;j < (n-i*r)/g+1;j++){
            if((n-r*i-g*j)%b == 0)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}