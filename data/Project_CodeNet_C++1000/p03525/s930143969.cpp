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

signed main(void){
    int N;
    int D[57];
    cin >> N;
    REP(i,N){
        cin >> D[i];
    }
    sort(D,D+N);
    int Ans=INF;
    vector<int> V;
    V.push_back(0);
    REP(i,N){
        if(i%2==0){
            V.push_back(D[i]);
        }else{
            V.push_back(24-D[i]);
        }
    }
    REP(i,V.size()){
        REP(j,V.size()){
            if(i==j)continue;
            Ans=min(Ans,abs(V[i]-V[j]));
        }
    }
    cout << Ans << endl;
    return 0;
}

