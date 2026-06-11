#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
ll a,b;
cin>>a>>b;
int k;
cin>>k;
map<int,int> m;
for(int i=a;i<min(a+k,b+1);i++){
cout<<i<<endl;
m[i]++;
}
if(min(a+k,b)==a+k){
for(int i=b-k+1;i<=b;i++){
if(m[i]==0)
cout<<i<<endl;
}
}


  return 0;
}
