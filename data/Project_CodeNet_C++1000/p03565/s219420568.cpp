#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    string s,t;
    cin >> s >>t;
    if(t.size()>s.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    string ans="{";
    for(int i = 0; i < s.size()-t.size()+1; i++) {
        bool a=true;
        for(int j = 0; j < t.size(); j++) {
            if(s[i+j]!=t[j] && s[i+j]!='?'){
                a=false;
            }
        }

        if(a){
            vector<char> y(s.size());
            for(int j = 0; j < s.size(); j++) {
                y[j]=s[j];
            }
            for(int j = i; j < i+t.size() ; j++) {
                y[j]=t[j-i];
            }
            for(int j = 0; j < s.size(); j++) {
                if(y[j]=='?') y[j]='a';
            }

            string q;
            for(int j = 0; j < s.size(); j++) {
                q += y[j];
            }
            if(ans>q) ans=q;
        }
    }

    if(ans=="{") cout << "UNRESTORABLE" << endl;
    else cout << ans << endl;

    return 0;
}