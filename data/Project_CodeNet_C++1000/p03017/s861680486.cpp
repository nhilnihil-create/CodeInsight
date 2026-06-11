#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    int n,a,b,c,d;
    string s;
    cin >> n >> a >> b >> c >> d;
    a--,b--,c--,d--;
    cin >> s;
    for (int i = a; i < c-1; ++i) {
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = b; i < d-1; ++i) {
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }

    if(c < d){
        cout << "Yes" << endl;
        return 0;
    }
    else{
        for (int i = b; i <= d; ++i) {
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}