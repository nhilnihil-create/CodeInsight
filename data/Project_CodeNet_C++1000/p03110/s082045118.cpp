#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<double> x(n);
    vector<string> u(n);
    double ans=0,BTC=0;
    for(int i=0;i<n;i++){
        cin>>x.at(i)>>u.at(i);
        if(u.at(i)=="JPY")
        ans+=x.at(i);
        else
        BTC+=x.at(i);
    }
    ans+=BTC/1*380000.0;
    cout<<ans<<endl;
}