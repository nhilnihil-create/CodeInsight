#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N;
int C[500],S[500],F[500];
int sumtime;

int Solve(int x){
    sumtime=S[x]+C[x];
    for(int i=x+1; i<N-1; i++){
        if(sumtime<=S[i])sumtime=S[i]+C[i];
        else {
            int t=(sumtime-S[i])/F[i];
            if(t*F[i]==sumtime-S[i])sumtime=S[i]+t*F[i]+C[i];
            else if(t*F[i]<sumtime-S[i])sumtime=S[i]+(t+1)*F[i]+C[i];
        }
    }
    return sumtime;
}

int main(){
    cin>>N;
    rep(i,N-1){
        cin>>C[i]>>S[i]>>F[i];
    }
    rep(i,N-1){
        sumtime=0;
        cout<<Solve(i)<<endl;
    }
    cout<<0<<endl;
    return 0;
}