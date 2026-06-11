#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
int main()
{
    string s;
    cin >> s;
    
    set<char> atcg;
    atcg.insert('A');
    atcg.insert('T');
    atcg.insert('C');
    atcg.insert('G');

    int ans = 0;
    int idx = 0;
    REP(i,s.size()){
        if( 0 != atcg.count(s[i])){
            idx++;
        }else{
            ans = max(ans,idx);
            idx = 0;
        }
    }
    ans = max(ans,idx);
    cout << ans << endl;
}