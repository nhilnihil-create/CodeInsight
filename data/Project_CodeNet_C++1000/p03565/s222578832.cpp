#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s,t; cin>>s>>t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    
    string s1 = s;
    
    int m = s.size();
    int n = t.size();
    
    rep(i, m){
        if(s[i] == t[0] || s[i] == '?'){
            int tmp = 0;
            rep(j, n){
                if(s[i+j]!=t[j] && s[i+j]!= '?'){
                    tmp = 1;
                    break;
            }
            }
            if(tmp == 0){
                rep(l,m){
                    if(l>=i && l < i+n)s1[l] = t[l-i];
                    else if(s[l]=='?')s1[l] = 'a';
//                    else s1[l] = s1[l];
                }
                reverse(s1.begin(),s1.end());
                cout<<s1<<endl;
                return 0;
            }
        }
    }
    cout<<"UNRESTORABLE"<<endl;
	return 0;
}