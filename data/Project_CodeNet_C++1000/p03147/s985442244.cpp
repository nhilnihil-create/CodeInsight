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
    vint H(N);
    cin >> H;
    int ans = 0;
    bool flag = true;
    while(flag){
        int st = 0;
        int mini = 100;
        REP(i,N+1){
            if(i == N || H[i] == 0){
                for(int j=st; j<i; j++){
                    H[j] -= mini;
                }
                if(st == i)mini=0;
                ans += mini;
                st = i+1;
                mini = 100;
            }else{
                chmin(mini,H[i]);
            }
        }
        flag = false;
        REP(i,N){
            if(H[i] != 0){
                flag = true;
                break;
            }
        }
    }
    cout << ans << endl;
}