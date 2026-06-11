#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s,t;
    cin>>s>>t;
    if (s[0]==t[2]&&s[2]==t[0]&&s[1]==t[1]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
