#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double x,sum=0;
    string u;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>u;
        if(u=="JPY"){
            sum+=x;
        }
        else if(u=="BTC"){
            sum+=(x*380000.0);
        }
    }
    cout<<sum;
    return 0;
}
