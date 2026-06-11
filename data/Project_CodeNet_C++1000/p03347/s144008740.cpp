#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) obj.begin(),obj.end()
#define pb(obj) push_back(obj)
#define REP(i,N) for(int i=0;i<N;i++)
typedef long long ll;
const ll MOD=1000000007;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int>A(N);
    bool flag=true;
    REP(i,N){
        cin>>A[i];
        if(A[i]>i){flag=false;}
    }
    if (flag==false){cout<<-1<<endl;exit(0);}
    ll sub=0;
    for(int i=N-1;i>=0;i--){
        if(i!=N-1){
            if(A[i+1]-A[i]==1){continue;}
            if(A[i+1]-A[i]>=2){cout<<-1<<endl;exit(0);}
        }
        sub+=A[i];
    }
    cout<<sub<<endl;
}