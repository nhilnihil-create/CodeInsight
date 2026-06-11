#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string s;cin>>s;
    int n = s.size();
    int low_c = 0;
    int cc = 0;
    rep(i,n)if(islower(s[i]))++low_c;
    for(int i=2;i<=n-2;++i)if(s[i]=='C')++cc;
    
    if(s[0]=='A' && n - low_c ==2 && cc == 1)cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
	return 0;
}