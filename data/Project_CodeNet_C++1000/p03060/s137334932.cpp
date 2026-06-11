#include<bits/stdc++.h>
using namespace std;
int main(){
int n,mx=0;
vector<pair<int,int> >v;
cin>>n;
int a[n+1],b[n+1];
for(int i=0;i<n;i++){
    cin>>a[i];
}
int sum=0;
for(int i=0;i<n;i++){
    cin>>b[i];
    sum+=(a[i]-b[i]);
}
for(int i=0;i<n;i++){
    if(a[i]-b[i]<0){
        sum-=(a[i]-b[i]);
    }
}
cout<<sum;
}