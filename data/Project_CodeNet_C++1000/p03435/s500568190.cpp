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
    int c[3][3] = {0};
    REP(i,3){
        REP(j,3){
            cin >> c[i][j];
        }
    }

    REP(i,101){
        REP(j,101){
            REP(k,101){
                bool flag = true;
                REP(l,3){
                    if(c[l][0]-i != c[l][1]-j || c[l][1]-j != c[l][2]-k){
                        flag = false;
                    }
                }
                if(flag){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}