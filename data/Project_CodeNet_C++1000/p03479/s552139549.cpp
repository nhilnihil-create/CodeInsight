#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll X,Y;
    cin >> X >> Y;
    int ans = 0;
    while(true){
        if (X > Y){
            break;
        }
        else{
            Y /= 2;
            ans += 1;
        }
    }
    cout << ans << endl;
}