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

int N;
int A[50];
vector<pair<int,int>> Ans;

void nondec(int l,int r){
    if(r<=l)return;
    int M=0,m=0;
    for(int i=l;i<=r;i++){
        if(A[M]<=A[i])M=i;
        if(A[m]>A[i])m=i;
    }
    if(A[M]==A[m])return;
    if(abs(A[M])>abs(A[m])){
        for(int i=l;i<=r;i++){
            Ans.push_back({M,i});
        }
        for(int i=l;i<r;i++){
            Ans.push_back({i,i+1});
        }
    }else{
        for(int i=l;i<=r;i++){
            Ans.push_back({m,i});
        }
        for(int i=r;i>l;i--){
            Ans.push_back({i,i-1});
        }
        
    }
}

signed main(void){
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }
    nondec(0,N-1);
    cout << Ans.size() << endl;
    REP(i,Ans.size()){
        cout << Ans[i].first+1 MM Ans[i].second+1 << endl;
    }
    return 0;
}

