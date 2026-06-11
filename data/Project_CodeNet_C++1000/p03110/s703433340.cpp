#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    long double ans = 0;
    long double b = 380000.0;
    rep(i,n){
        long double x;cin>>x;
        string s;cin>>s;
        if(s=="JPY")ans+=x;
        else ans+=b*x;
    }
    cout<<ans<<endl;
	return 0;
}