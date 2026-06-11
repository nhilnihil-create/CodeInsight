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
    
    ll N,a,b;
    vector<ll> A,B;
    bool dif=false;
    cin >> N;
    ll All=0;
    REP(i,N){
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
        if(a!=b){
            dif=true;
        }
        All+=a;
    }
    
    if(!dif){
        cout << 0 << endl;
        return 0;
    }
    
    ll Ans=INF;
    REP(i,N){
        if(A[i]>B[i]){
            Ans=min(Ans,B[i]);
        }
    }
    
    cout << All-Ans << endl;
    
    return 0;
}

