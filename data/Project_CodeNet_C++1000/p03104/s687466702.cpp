#include <bits/stdc++.h>

using namespace std;
 
//#define int long long
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define reps(i,n) for(ll i=0;i<=n;i++)

ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
 
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    ios_base::sync_with_stdio(false);
    ll a,b,ans=0;
    cin >> a >> b;

    if(a==b){
        cout << a << endl;
        return 0;
    }

    if(b == a+1){
        ans = a^(a+1);
        cout << ans << endl;
        return 0;
    }

    if(a%2==0){
        if((b-a)%2==1){
            if((((b-a)/2))%2==0){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }else{
            if((((b-a)/2))%2==0){
                cout << b << endl;
                }else{
                    ans = 1^b;
                    cout << ans << endl;
                }
        }
    }else{ //aが奇数のとき
        if(((b-a)/2)%2==0){
            ans = 0;
        }else{
            ans = 1;
        }
        if((b-a)%2==0){
            ans ^= a;
        }else{
            ans = ans ^ a ^ b;
        }
            cout << ans << endl;
        }
    return 0;
}
