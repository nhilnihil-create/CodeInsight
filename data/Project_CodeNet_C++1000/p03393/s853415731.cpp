#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s;
    cin >> s;
    vector<bool> che(26);
    rep(i,s.size()) che[s[i]-'a'] = 1;
    if(s.size() <= 25){
        rep(i,26){
            if(!che[i]){
                s += 'a' + i;
                cout << s << endl;
                return 0;
            } 
        }
    }else{
        for(int i=s.size()-1;i>=0;i--){
            che[s[i] - 'a']=0;
            for(int j=s[i]-'a'+1;j<26;j++){
                if(!che[j]){
                    s[i] = (char)j + 'a';
                    s = s.substr(0,i+1);
                    cout << s << endl;
                    return 0;
                }
            }
        }
        cout << -1 << endl;
    }
}