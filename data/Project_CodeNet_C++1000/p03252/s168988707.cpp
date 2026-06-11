#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
    string s, t; cin >> s >> t;
    int len = s.size();
    
    vector<int> num(26, -1);//出現順、未出現なら-1
    string s_, t_;  vector<char> alp;
    for(char c='a'; c<='z'; c++)alp.push_back(c);

    int index = 0;
    for(char c: s){
        int i = c - 'a';
        if(num[i]==-1){
            s_.push_back(alp[index]);
            num[i] = index;
            index++;
        }else{
            s_.push_back(alp[num[i]]);
        }
    }
    index = 0; rep(i, 26)num[i] = -1;
    for(char c: t){
        int i = c - 'a';
        if(num[i]==-1){
            t_.push_back(alp[index]);
            num[i] = index;
            index++;
        }else{
            t_.push_back(alp[num[i]]);
        }
    } 
    //cout << s_ << " " << t_ << ln;
    cout << (s_==t_? "Yes":"No") << ln;  
}