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
#define GOODBYE do { cout << -1 << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    string S;
    cin >> S;
    int N=S.size();
    vector<pair<int,int>> Ans;
    if(S[N-1]!='0')GOODBYE;
    if(S[0]!='1')GOODBYE;
    if(S[N-2]!='1')GOODBYE;
    REP(i,N-1){
        if(S[i]!=S[N-2-i])GOODBYE;
    }
    int now=0;
    REP(i,N-1){
        Ans.push_back({now,i+1});
        if(S[i]=='1'){
            now=i+1;
        }
    }
    
    REP(i,Ans.size()){
        cout << Ans[i].first+1 MM Ans[i].second+1 << endl; 
    }
    
  return 0;
}

