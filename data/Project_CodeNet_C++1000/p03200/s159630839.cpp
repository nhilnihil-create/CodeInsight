#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_editorial
int main() {
    string s;cin>>s;
    int n = s.size();
    
    ll ans = 0;
    ll tmp = 0;
    rep(i,n){
        if(s[i]=='B')++tmp;
        else ans+=tmp;
    }
    cout<<ans<<endl;
	return 0;
}