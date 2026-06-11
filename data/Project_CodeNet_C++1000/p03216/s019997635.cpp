#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "No" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N,Q,K[100];
    string S;
    cin >> N >> S >> Q;
    REP(i,Q){
        cin >> K[i];
    }
    
    int D[1114514]={},M[1114514]={};
    REP(i,N){
        if(S[i]=='D'){D[i]++;}
        if(S[i]=='M'){M[i]++;}
        if(i!=0){
            D[i]+=D[i-1];
            M[i]+=M[i-1];
        }
        
    }
    
    REP(_,Q){
        int k=K[_];
        int A=0,C=0;
        REP(i,N){
            if(S[i]=='M'){if(i>=k){A-=D[i-k];}if(i!=0){A+=D[i-1];}}
            if(S[i]=='C'){C+=A;}
            if(i-k+1>=0 && S[i-k+1]=='D'){A+=M[i-k+1];if(i!=0){A-=M[i];}}
        }
        cout << C << endl;
    }
    return 0;
}

