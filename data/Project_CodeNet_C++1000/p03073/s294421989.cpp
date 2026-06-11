//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 2e6 + 5;
const int M = 1e5 + 5;
const int OO = 2e9;
const int mod = 1e9 + 7;

int s1,s2;
string s;

void init() {



}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    for (int i = 0; i < s.size(); ++i) {

        if(i&1) {

            if(s[i]=='1') ++s1;
            else ++s2;

        } else {

            if(s[i]=='0') ++s1;
            else ++s2;

        }

    }

    cout << min(s1, s2) << '\n';

    return 0;
}