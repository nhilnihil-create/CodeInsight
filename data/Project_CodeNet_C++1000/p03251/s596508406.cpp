#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;
    vector<int>x(N);
    vector<int>y(M);
    int a=-1000;
    int b=1000;
    rep(i,N){
        cin>>x[i];
        if(a<x[i]){
            a=x[i];
        }
    }
    rep(i,M){
        cin>>y[i];
        if(y[i]<b){
            b=y[i];
        }
    }
    bool ans=false;
    for(int i=X+1; i<Y+1; i++){
        if(a<i&&i<=b){
            ans=true;
        }
    }
    if(ans==false){
        cout<<"War"<<endl;
    }
    else{
        cout<<"No War"<<endl;
    }
}
