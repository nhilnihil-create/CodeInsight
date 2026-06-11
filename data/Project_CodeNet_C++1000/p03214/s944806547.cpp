#include<bits/stdc++.h>
#define ll long long
using namespace std;
double a[10000],sum;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
        sum+=a[i];
    }
    sum/=n;
    double d=1000000;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]>sum&&(a[i]-sum)<d){
            d=a[i]-sum;
            ans=i;
        }
        if(a[i]<=sum&&(sum-a[i])<d){
            d=sum-a[i];
            ans=i;
        }
    }
    cout<<ans<<endl;


}