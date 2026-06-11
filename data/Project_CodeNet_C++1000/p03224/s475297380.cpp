#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 10000000000000009
//#define INF 9223372036854775807
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ORREP(i,n) for(int i=(n);i>=1;--i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define rollcall cout<<"I'm Sucu."<<endl;
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define Taka(s) s?cout << "Takahashi" << endl:cout << "Aoki" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl
typedef pair<int,int> Pp;

signed main(){
    int N;
    cin >> N;
    int M=8*N+1;
    M=sqrt(M);
    if(M*M!=8*N+1){
        cout << "No" << endl;return 0;
    }
    M=(M-1)/2;
    cout << "Yes" << endl << M+1 << endl;
    int e=0;
    bool D[500][100000]={};
    REP(i,M){
        REP(j,M-i){
            D[i][e+j]=1;
            D[i+j+1][e+j]=1;
        }
    	e+=M-i;
    }
    /*REP(i,M){
        REP(j,N){
            cout << D[i][j] << " ";
        }cout << endl;
    }cout << endl;*/
  	
    REP(i,M+1){
        cout << M <<" ";
        REP(j,N){
            if(D[i][j]==1){
                cout << j+1 << " ";
            }
        }cout << endl;
    }
    
    return 0;
}   
