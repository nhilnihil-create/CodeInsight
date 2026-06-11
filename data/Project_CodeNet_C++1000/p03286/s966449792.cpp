#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;
    ll n;
    cin >> n;

    string s = "";

    while(n != 0) {
        if(n % 2 != 0) {
            n--;
            s += "1";
        }
        else {
            s += "0";
        }

        n  /= (-2);
    }
    reverse(s.begin(), s.end());
    if(s.size() == 0) {
        cout << 0 << endl;
    }
    else {
        cout << s << endl;
    }
    return 0;
}
