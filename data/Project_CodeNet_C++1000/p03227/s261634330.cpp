#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define INF 9000000000000000000
signed main() {
    string s;cin>>s;
    if(s.size()==2)cout<<s<<endl;
    else{
        reverse(all(s));cout<<s<<endl;
    }
}