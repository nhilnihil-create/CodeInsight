#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    string s; cin >> s;
    int len = s.size(); bool fg = true;
    if(s.back()=='1')fg = false;
    if(s[0] == '0' || s[len-2] == '0')fg = false;
    s.pop_back(); int num = len/2;
    string a = s.substr(0, num);
    if(len%2==0)num--;
    string b = s.substr(num);
    reverse(all(b));
    if(a != b)fg = false;

    vector<int> vec;
    rep(i, len-1)if(s[i]=='1')vec.push_back(i + 1);
    vector<pii> res;
    int par = 1, child = 2, index = 0;
    if(fg){
    for(int siz = 1; siz < len; siz++){
        //cout << "siz:" << siz << " vec:" << vec[index] << ln;
        if(siz <= vec[index]){
            res.push_back({par, child});
            child++;
        }else{
            par = child - 1;
            res.push_back({par, child});
            child++;
            index++;
        }
    }
        for(auto p: res){
            cout << p.first << " " << p.second << ln;
    }
    }else{
        cout << -1 << ln;
    }
}
