#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    cin>>n;
    string s;
    while(1) {
        s=to_string(n);
        if (s[0]==s[1]&&s[1]==s[2]) {
            cout<<s<<endl;
            return 0;
        }
        n++;
    }
}
