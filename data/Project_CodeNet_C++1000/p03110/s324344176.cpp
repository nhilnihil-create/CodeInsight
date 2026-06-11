#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double ans=0;
    for(int i=0;i<n;i++){
        double x;
        string s;
        cin>>x>>s;
        if(s=="BTC") x*=380000;
        ans+=x;
    }
    cout<<ans<<endl;
}