#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main(){
    int N,A,B;
    cin>>N>>A>>B;
    vector<int>P(N);
    int D=0;
    int E=0;
    int F=0;
    rep(i,N){
        cin>>P[i];
        if(P[i]<=A){
            D++;
        }
        else if(P[i]<=B){
            E++;
        }
        else
        {
            F++;
        }
        
    }
    int G=min(D,E);
    cout<<min(G,F)<<endl;
}