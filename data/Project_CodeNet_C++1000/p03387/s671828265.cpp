#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int a[5],ans=0,ma;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[2]%2==(a[0]+a[1]+a[2])%2){
        ma=a[2];
    }
    else{
        ma=a[2]+1;
    }
    int ans1=0;
    for(int i=0;i<3;i++){
        if(ma%2!=a[i]%2){
            a[i]++;
            ans1++;
        }
        ans+=(ma-a[i])/2;
    }
    cout<<ans+ans1/2<<endl;

    return(0);
}