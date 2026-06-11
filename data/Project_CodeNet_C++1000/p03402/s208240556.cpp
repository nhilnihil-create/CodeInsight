#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define INF 10000000000000009
#define INF 9223372036854775807
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


signed main(){
    int A,B;
    cin >> A >> B;
    A--;B--;
    cout << "100 100" << endl;
    char C[570][570];
    REP(i,100){
        REP(j,50){
            C[i][j]='#';
            C[i][j+50]='.';
        }
    }
    REP(i,A){
        C[2*(i/20) +1][2*(i%20)]='.';
    }
    REP(i,B){
        C[2*(i/20) +1][50+2*(i%20)+1+5]='#';
    }
    REP(i,100){
        REP(j,100){
            cout << C[i][j];
        }cout << endl;
    }cout << endl;
    return 0;
}   
