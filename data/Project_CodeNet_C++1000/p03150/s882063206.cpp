#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    string ans = "keyence";
    string s;cin>>s;
    int window = s.size()-7;
    for(int i=0;i<=s.size()-window;i++){
        string tmp="";
        tmp.append(s.substr(0,i));
        tmp.append(s.substr(i+window));
        if(ans==tmp){co("YES");return 0;}
    }
    co("NO");
}