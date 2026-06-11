#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define all(x) (x).begin(), (x).end()
#define v(T) vector<T>
#define vv(T) vector<v(T)>
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
int main()
{
    int n;
    cin >> n;
    bool flag = 0;
    if (n < 0) flag ^= 1;
    n = abs(n);
    if (n==0){
        cout << 0 << endl;
        return 0;
    }
    string ans = "";
    while (n > 0){
        ans += to_string(n%2);
        if (flag) n++;
        n >>= 1;
        flag ^= 1;
    }
    reverse(all(ans));
    cout << ans << endl;
}
