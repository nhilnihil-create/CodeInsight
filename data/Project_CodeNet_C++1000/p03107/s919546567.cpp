#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;++i)

int main() {
    string s;cin>>s;
    int n = s.size();
    
    int a[2];
    a[0] = a[1] = 0;
    rep(i,n){
        if(s[i]=='0')++a[0];
        if(s[i]=='1')++a[1];
    }
    cout<<2*min(a[0],a[1])<<endl;
	return 0;
}