#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    int a,b,c,x;cin>>a>>b>>c>>x;
    int res=0;
    rep(i,0,a+1){
        rep(j,0,b+1){
            rep(k,0,c+1){
                if(500*i+j*100+k*50==x)res++;
            }
        }
    }
    cout<<res<<endl;
}