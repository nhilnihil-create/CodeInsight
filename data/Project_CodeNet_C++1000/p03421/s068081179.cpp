#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PP;
#define MOD 1000000007
//#define MOD 998244353
#define INF 2305843009213693951
//#define INF 810114514
#define PI 3.141592653589
#define setdouble setprecision
#define REP(i,n) for(ll i=0;i<(n);++i)
#define OREP(i,n) for(ll i=1;i<=(n);++i)
#define RREP(i,n) for(ll i=(n)-1;i>=0;--i)
#define all1(i) begin(i),end(i)
#define GOODBYE do { cout << "-1" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false
#define debug2 false

int main(void){
    ll N,A,B;
    cin >> N >> A >> B;
    
    if(A*B<N){GOODBYE;}
    if(A+B>N+1){GOODBYE;}
    
    
    vector<ll> D(B,1);
    ll remain = N-B;
    REP(i,B){
        if(remain>=A-1){
            D[i]+=A-1;
            remain -= A-1;
        }else{
            D[i]+=remain;
            remain=0;
        }
    }
    
    vector<ll> Ans;
    remain = N;
    
    REP(j,D.size()){
        for(ll i=remain-D[j]+1;i<=remain;i++){
            Ans.push_back(i);
        }
        remain-=D[j];
    }
    
    REP(i,N){
        if(i!=0){cout << " ";}
        cout << Ans[i];
    }
    cout << endl;
    
    return 0;
}

