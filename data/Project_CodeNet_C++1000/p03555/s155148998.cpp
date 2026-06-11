#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s,t;cin>>s>>t;
    reverse(s.begin(),s.end());
    if(s==t)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0;
}