#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    vint A(4);
    char op[] = {'+','-'};
    string inp;
    cin >> inp;
    REP(i,4){
        A[i] = inp[i]-'0';
    }
    string ans;
    REP(i,2){
        int calc1 = A[0];
        if(i == 0){
            calc1 += A[1];
        }else{
            calc1 -= A[1];
        }
        REP(j,2){
            int calc2 = calc1;
            if(j == 0){
                calc2 += A[2];
            }else{
                calc2 -= A[2];
            }
            REP(k,2){
                int calc = calc2;
                if(k == 0){
                    calc += A[3];
                }else{
                    calc -= A[3];
                }
                if(calc == 7){
                    cout << A[0] << op[i] << A[1] << op[j] << A[2] << op[k] << A[3] << "=7" << endl;
                    return 0;
                }
            }
        }
    }
}