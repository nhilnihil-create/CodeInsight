#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
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

int BE(int b,int e){
    int r=1;
    while(e){
        if(e&1){
            r=(r*b)%MOD;
        }
        b=(b*b)%MOD;
        e >>=1;
    }
    return r;
}



signed main(void){
    int N;
    int A[114514];
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }
    
    int inv[114514]={};
    int invsum[114514]={};
    REP(i,N+2){
        if(i==0)continue;
        inv[i]=BE(i,MOD-2);
    }
    REP(i,N+1){
        invsum[i+1]=invsum[i]+inv[i+1];
    }
    int Ans=0;
    REP(i,N){
        int sum=0;
        sum+=invsum[i+1];
        sum+=invsum[N-i];
        sum-=1;
        sum=(sum+MOD)%MOD;
        sum=(sum*A[i])%MOD;
        Ans=(sum+Ans)%MOD;
    }
    REP(i,N+1){
        if(i==0)continue;
        Ans=(Ans*i)%MOD;
    }
    cout << Ans << endl;
    return 0;
}

