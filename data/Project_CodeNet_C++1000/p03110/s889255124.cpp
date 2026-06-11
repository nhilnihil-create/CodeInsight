#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    double sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        double x; string u;
        cin>>x>>u;
        if(u=="JPY") sum+=x;
        else sum+=x*380000.0;
    }
    cout<<fixed<<setprecision(8)<<sum<<endl;
    return 0;
}