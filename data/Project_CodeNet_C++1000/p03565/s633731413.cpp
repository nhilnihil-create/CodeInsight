#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s,t;
    cin >> s >> t;
    if(s.length()<t.length()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    int ans = 0;
    int sum = 0;
    bool ok = false;
    rep(i,s.length()-t.length()+1){
        string x = s.substr(i,t.length());
        rep(j,t.length()){
            if(x[j] == '?'){
                sum++;
                continue;
            }
            else if(x[j] == t[j]){
                sum++;
                continue;
            }
            else break;
        }
        if(sum == t.length()) {
            ans = i;
            ok = true;
        }
        sum = 0;
    }
    if(!ok) cout << "UNRESTORABLE" << endl;
    else{
        rep(i,s.length()){
            if(s[i] == '?'&&i != ans){
                s[i] = 'a';
            }else if(i == ans){
                rep(j,t.length()){
                    s[i+j] = t[j];
                }
                i += t.length()-1;
            }
        }
        cout << s << endl;
    }
    

    return 0;
}
