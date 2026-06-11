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
    int N;
    cin >> N;
    vll A(N);
    vll B(N);
    cin >> A;
    REP(i,N){
        B[i] = A[i];
    }
    int half = N/2;
    sort(B.begin(),B.end());
    REP(i,N){
        if(A[i] < B[half]){
            cout << B[half] << endl;
        }else{
            cout << B[half-1] << endl;
        }
    }
}