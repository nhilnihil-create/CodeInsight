#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    long double ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int c=0,b=i;
        while(b<k){
            c++;
            b*=2;
        }
        ans+=pow(0.5,c)*(long double)(1.0/n);
    }
    cout<<fixed << std::setprecision(9)<<ans<<endl;
    return(0);
}