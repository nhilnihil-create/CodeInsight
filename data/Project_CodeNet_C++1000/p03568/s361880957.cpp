#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a[15],o[105],no[105],ans=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            no[i]=2;
        }
        else{
            no[i]=1;
        }
        if(i!=0)
            no[i]*=no[i-1];
        ans*=3;
    }
    ans-=no[n-1];
    cout<<ans<<endl;
    return(0);
}