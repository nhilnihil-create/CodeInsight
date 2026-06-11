#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;
//const int MOD = 1000000007;
const int MOD = 998244353;
const int INF = 1001001001;

int main(){
    string s;
    cin >> s;
    if(s.size()<15){
        for(int i=s.size(); i<=15; i++){
            s.push_back('o');
        }
    }
    
    map<char,int> m;
    rep(i,15)m[s[i]]++;
    
    if(m['o']>=8)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}