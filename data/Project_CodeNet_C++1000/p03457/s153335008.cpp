#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    int N;cin>>N;
    vector<int>X(N+1),Y(N+1),T(N+1);
    X[0]=0;
    Y[0]=0;
    T[0]=0;
    rep(i,0,N)cin>>T[i+1]>>X[i+1]>>Y[i+1];
    rep(i,0,N){
        int dt=T[i+1]-T[i];
        int dist=abs(X[i+1]-X[i])+abs(Y[i+1]-Y[i]);
        if(dt<dist){
            cout<<"No"<<endl;
            return 0;
        }
        if(dt%2!=dist%2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}