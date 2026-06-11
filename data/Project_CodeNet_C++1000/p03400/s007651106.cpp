#include <bits/stdc++.h>
using namespace std;
int n,x,a[150],d,sum,k,s;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n>>d>>x;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
        for(int j=1;j<=d;j++){
            sum=0;
    sum+=(j*a[i]+1);
    if(sum<=d)k++;
}}
s+=k;
s+=n;
s+=x;
cout<<s;

return 0;}

