#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    int ans=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){
        if(a[i]>b[i])ans+=a[i]-b[i];
    }
    cout<<ans<<endl;
    return 0;
}