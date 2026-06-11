#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N,M;
    int A[12];
    int d[10]={0,2,5,5,4,5,6,3,7,6};
    cin >> N >> M;
    REP(i,M){
        cin >> A[i];
    }
    sort(A,A+M,greater<>());
    vector<int> dp(20000,-1);
    dp[0]=0;
    REP(i,N){
        REP(j,M){
            dp[i+d[A[j]]]=max(dp[i+d[A[j]]],dp[i]+1);
        }
    }
    /*REP(i,N+1){
        cout << dp[i] << " ";
    }cout << endl;*/
    
    int k = N;
    while(k>0){
        REP(i,M){
            if(k-d[A[i]]>=0 && dp[k]-dp[k-d[A[i]]]==1){
                cout << A[i];
                k-=d[A[i]];
                break;;
            }
        }
    }
    return 0;
}

