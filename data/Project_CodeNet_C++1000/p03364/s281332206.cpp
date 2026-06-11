#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
int main(){
    int n;
    char S[300][300],T[300][300];
    cin>>n;
    rep(i,n)rep(j,n) cin>>S[i][j];
    int ans=0;
    rep(i,n){
        int z=1;
        rep(j,n)rep(k,n) T[j][k]=S[(j+i)%n][k];
        rep(j,n)rep(k,n) if(T[j][k]!=T[k][j]) z=0;
        if(z) ans++;
    }
    cout<<ans*n;
}