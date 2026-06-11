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
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    int N;
    cin >> N;
    map<char,ll> cnt;
    vector<char> comb{'M','A','R','C','H'};
    REP(i,N){
        string s;
        cin >> s;
        cnt[s[0]]++;
    }
    ll ans = 0;
    for(int bit=0; bit<(1<<5); bit++){
        vint idx;
        for(int i=0; i<5; i++){
            if(bit & (1<<i))idx.pb(i);
        }
        if(idx.size()!=3)continue;
        ans += 1LL*cnt[comb[idx[0]]]*cnt[comb[idx[1]]]*cnt[comb[idx[2]]];
    }
    cout << ans << endl;
    
}
