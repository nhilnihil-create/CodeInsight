#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int a[3],k;
    for(int i=0;i<3;i++)cin>>a[i];
    cin>>k;
    sort(a,a+3);
    int ans=a[0]+a[1]+a[2]*pow(2,k);
    cout<<ans<<endl;
    return 0;
}