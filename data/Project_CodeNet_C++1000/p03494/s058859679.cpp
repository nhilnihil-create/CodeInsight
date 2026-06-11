#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    int n;cin>>n;
    vector<int>A(n);
    rep(i,0,n)cin>>A[i];
    int res=100;
    rep(i,0,n){
        int tmp=0;
        while(A[i]%2==0){
            A[i]/=2;
            tmp++;
        }
        if(tmp<res)res=tmp;
    }
    cout<<res<<endl;
}