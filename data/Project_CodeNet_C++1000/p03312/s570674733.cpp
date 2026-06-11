#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << -1 << endl;return 0
#define Endl endl

signed main(void){
    int N;
    int A[214514];
    int B[214514]={};
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }
    REP(i,214514){
        B[i]=INF;
    }
    B[0]=A[0];
    REP(i,N-1){
        B[i+1]=B[i]+A[i+1];
    }
    
    
    int Ans=INF;
    int i=0,k=2;
    //REP(i,N){cout << B[i] << " ";}cout << endl;
    int P[4];
    REP(j,N){
        if(j==0)continue;
        //0~j-1から選ぶ,j~N-1から選ぶ
        int sum1,sum2;
        while(1){
            sum1=abs(B[j]-2*B[i]),sum2=abs(B[j]-2*B[i+1]);
            if(sum1>sum2){
                i++;
            }else{
                break;
            }
        }
        
        while(1){
            sum1=abs(B[N-1]-B[k]-B[k]+B[j]),sum2=abs(B[N-1]-B[k+1]-B[k+1]+B[j]);
            if(sum1>sum2){
                k++;
            }else{
                break;
            }
        }
        
        P[0]=B[i];
        P[1]=B[j]-B[i];
        P[2]=B[k]-B[j];
        P[3]=B[N-1]-B[k];
        sort(P,P+4);
        Ans=min(Ans,P[3]-P[0]);
        //cout << i << " " << j << " " << k << " "<<P[3]-P[0] << endl;
    }
    cout << Ans << endl;
    
    return 0;
}

