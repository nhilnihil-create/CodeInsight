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
    ll N;
    vll A(5);
    cin >> N;
    cin >> A;
    ll ans = 0;
    ll C;
    for(int i=0; i<5; i++){
        if(i == 0){
            C = A[i];
            ans = N/A[i];
            if(0 != N%A[i])ans++;
        }else{
            if(C > A[i]){
                C = A[i];
                ans = N/A[i] + i;
                if(0 != N%A[i])ans++;
            }else{
                ans++;
            }
        }
    }
    cout << (ans) << endl;
}