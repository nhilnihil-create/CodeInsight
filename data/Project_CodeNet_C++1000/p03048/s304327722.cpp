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
    ll R,G,B,N;
    cin >> R >> G >> B >> N;
    ll tmp;
    ll ans = 0;
    for(int r=0; r<= 3000; r++){
        for(int g=0; g<= 3000; g++){
            tmp = N - (R*r + G*g);
            if(tmp < 0)break;
            if(0 == tmp%B)ans++;
        }
    }
    cout << ans << endl;
}