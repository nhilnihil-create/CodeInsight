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
    string S;
    cin >> S;
    if(S == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }

    vint cnt(26,-1);
    REP(i,S.size()){
        cnt[S[i]-'a'] = i;
    }
    if(S.size() < 26){
        cout << S ;
        REP(i,26){
            if(cnt[i] == -1){
                cout << (char)('a'+i) << endl;;
                break;
            }
        }
        return 0;
    }
    string T = S;
    next_permutation(T.begin(),T.end());
    int idx = -1;
    REP(i,S.size()){
        if(T[i] != S[i]){
            idx = i;
            break;
        }
    }
    cout << T.substr(0,idx+1) << endl;
}