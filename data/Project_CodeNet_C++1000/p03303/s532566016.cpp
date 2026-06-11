#include<bits/stdc++.h>

using namespace std;
#define sz(x) (ll)(x.size())
typedef long long ll;

int main(){
    string s; cin>>s;
	ll n; cin>>n;
    for(int i=0;i<sz(s);i+=n) cout<<s[i];
}
