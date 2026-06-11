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
    string s, t;
    cin >> s >> t;
    vector<ll>sv(26);
    vector<ll>tv(26);


    for (ll i = 0; i < s.size(); i++) {
        sv[s[i] - 'a']++;
        tv[t[i] - 'a']++ ;
    }

    sort(sv.begin(), sv.end());
    sort(tv.begin(), tv.end());

    for (ll i = 0; i < sv.size(); i++) {
        if(sv[i] != tv[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
