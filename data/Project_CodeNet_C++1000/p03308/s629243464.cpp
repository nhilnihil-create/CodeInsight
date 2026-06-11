#include<bits/stdc++.h>
using namespace std;
int main(void){
int n;cin>>n;
int x[n];
for(int i=0;i<n;i++)
    cin>>x[i];
sort(x,x+n);
cout<<abs(x[0]-x[n-1])<<endl;
return 0;}
