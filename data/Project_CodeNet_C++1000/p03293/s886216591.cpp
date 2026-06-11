#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string s,t;cin>>s>>t;
    int n = s.size();
    rep(i,n){
        int tmp=0;
        rep(j,n){
            if(s[j]!=t[(i+j)%n])tmp=1;
    }
    if(tmp==0){
        cout<<"Yes"<<endl;
        return 0;
    }
    }
    cout<<"No"<<endl;
	return 0;
}

