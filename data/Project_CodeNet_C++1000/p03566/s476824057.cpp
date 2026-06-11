#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;

double func(double a,double b,double t,double v){
    if(a<=t&&t<=b) return v;
    if(t<a) return v+(a-t);
    return v+(t-b);
}

int main(){
    
    int N;cin>>N;
    vector<double> T(N+1,0),V(N);
    for(int i=0;i<N;i++){
        cin>>T[i+1];
        T[i+1]+=T[i];
    }
    for(int i=0;i<N;i++){
        cin>>V[i];
    }
    
    vector<double> S(T[N]*2+1);
    int j=0;
    for(double t=0.0;t<=T[N];t+=0.5){
        double v=1000.0;
        for(int i=0;i<N;i++){
            v=min(v,func(T[i],T[i+1],t,V[i]));
        }
        v=min(v,t);
        v=min(v,T[N]-t);
        S[j]=v;
        j++;
    }
    double ans=0.0;
    for(int i=1;i<2*T[N]+1;i++){
        ans+=0.25*(S[i-1]+S[i]);
    }
    
    cout<<setprecision(15)<<ans<<endl;
}
