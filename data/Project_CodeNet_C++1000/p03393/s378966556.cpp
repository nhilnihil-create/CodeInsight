#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
bool used[26];
int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(n<26){
        rep(i,n) used[s[i]-'a'] = true;
        rep(i,26){
            if(!used[i]){
                s += char('a' + i);
                cout << s << endl;
                return 0;
            }
        }
    }
     used[s[25]-'a'] = true;
     string s2 = s;
     s2.pop_back();
     s2.pop_back();
    for(int i=25; i>0; i--){
        if(s[i-1]>s[i]){
            used[s[i-1]-'a'] = true;
            if(!s2.empty())s2.pop_back();
            continue;
        }
        rep(j,n){
            //cout << s[j-1] << endl;
            if(used[j]&&s[i-1]-'a'<j) {
                s2+=(char)('a'+j);
                cout << s2 << endl;
                return 0;
            }
        }
        return 0;
    }
    cout << -1 << endl;
    return 0;
}