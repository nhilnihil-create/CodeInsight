#include <bits/stdc++.h>
using namespace std;

#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;


int main() {

    string s;
    cin >> s;
    char op1, op2, op3;

    for ( op1 = '+'; ; op1 = '-' ) {
        for ( op2 = '+'; ; op2 = '-' ) {
            for ( op3 = '+'; ; op3 = '-' ) {
                int soma = 0;
                if ( op1 == '+' ) soma += s[0] - '0' + s[1] - '0';
                else soma += (s[0] - '0') - (s[1] - '0');

                if ( op2 == '+' ) soma += s[2] - '0';
                else soma -= (s[2] - '0');

                if ( op3 == '+' ) soma += s[3] - '0';
                else soma -= (s[3] - '0');

                if ( soma == 7 ) {
                    cout << s[0] << op1 << s[1] << op2 << s[2] << op3 << s[3] << "=7\n";
                    return 0;
                }

                if ( op3 == '-' ) break;
            }
            if ( op2 == '-' ) break;
        }
    }

    return 0;
}