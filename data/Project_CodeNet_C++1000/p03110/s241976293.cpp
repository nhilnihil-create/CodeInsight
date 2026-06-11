#include<bits/stdc++.h>

using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<double> x(N);
    vector<string> u(N);
    for(int i=0;i<N;i++){
        cin>>x[i]>>u[i];
    }
    double ans=0.0;
    for(int i=0;i<N;i++){
        if(u[i]=="JPY") ans+=x[i];
        if(u[i]=="BTC") ans+=x[i]*380000.0;
    }
    cout<<fixed;
    cout<<setprecision(6)<<ans<<endl;
    return 0;
}
