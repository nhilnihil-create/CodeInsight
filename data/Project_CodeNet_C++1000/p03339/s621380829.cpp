#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
char c[n];
int W=0,E=0;
rep(i,n){
cin>>c[i];
if(c[i]=='E')
E++;
}
int M=1000000;
rep(i,n){
  int count;
if(c[i]=='E'){
  E--;
count=W+E;
}
else
{
  count=W+E;
  W++;
}
//cout<<count<<endl;
M=min(M,count);
}
cout<<M<<endl;
  return 0;
}
