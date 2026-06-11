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
    cin >> A;
    while(1){
        sort(A.begin(),A.end());
        int st=1;
        ll a = 0;
        REP(i,N-1){
            if(0 != A[i]){
                st=i;
                a = A[i];
                break;
            }
        }
        if(0 == a)break;
        for(int i=st+1; i<N; i++){
            A[i] %= a;
        }
    }
    cout << A[N-1] << endl;
}