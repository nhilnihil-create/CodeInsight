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
    int N,K;
    int t,d;
    vector<pair<int,int>> DT;
    cin >> N >> K;
    REP(i,N){
        cin >> t >> d;
        DT.push_back({d,t});
    }
    sort(DT.begin(),DT.end(),greater<>());
    vector<int> F,G;
    bool f[114514]={};
    REP(i,N){
        if(!f[DT[i].second]){
            F.push_back(DT[i].first);
            f[DT[i].second]=true;
        }else{
            G.push_back(DT[i].first);
        }
    }
    
    //REP(i,F.size()){cout << F[i] << " ";}cout << endl;
    //REP(i,G.size()){cout << G[i] << " ";}cout << endl;
    REP(i,(int)(F.size())-1){
        F[i+1]+=F[i];
    }
    REP(i,(int)(G.size())-1){
        G[i+1]+=G[i];
    }
    
    //REP(i,F.size()){cout << F[i] << " ";}cout << endl;
    //REP(i,G.size()){cout << G[i] << " ";}cout << endl;
    
    int Ans=0;
    REP(i,K+1){
        if(F.size()<i || G.size()<K-i)continue;
        int num=(i)*(i);
        if(i!=0){
            num+=F[i-1];
        }
        if(K-i!=0 && K-i-1<G.size()){
            num+=G[K-i-1];
        }
        //cout << i MM num << endl;
        Ans=max(Ans,num);
    }
    cout << Ans << endl;
    return 0;
}

