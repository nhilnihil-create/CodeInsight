#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s;
    ll k;
    cin>>s>>k;
    for (int i=0; i<min(k,(ll)s.size()); i++) {
        if (s[i]!='1') {
            cout<<s[i]<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
}
