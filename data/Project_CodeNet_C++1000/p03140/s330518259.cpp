#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mod 1000000007
 
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
 
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int cnt = 0;
        if (a[i] != b[i]) cnt++;
        if (b[i] != c[i]) cnt++;
        if (c[i] != a[i]) cnt++;

        if(cnt == 2) ans++;
        else if(cnt >= 3) ans += 2;
    }
    cout << ans << endl;
    return 0;
}