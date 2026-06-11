#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,K;
    cin>>N>>K;
    int A[N];
    rep(i,N)A[i]=0;
    int kind=0;
    rep(i,N){
        int a; cin>>a;
        if(A[a-1]==0)kind++;
        A[a-1]++;
    }
    int ans=0;
    sort(A,A+N);
    int i=0;
    while(kind>K){
        if(A[i]!=0){
            kind--;
            ans+=A[i];
        }
        i++;
    }
    cout<<ans<<endl;
    return 0;
}