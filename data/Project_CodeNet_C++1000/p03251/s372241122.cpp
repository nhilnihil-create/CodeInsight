#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define INF 1000000000000


signed main(){
int n,m,x,y;
cin>>n>>m>>x>>y;
int hantei;
int a[n],b[m];
rep(i,n){cin>>a[i];}
rep(i,m){cin>>b[i];}

for(int i=x+1;i<=y;i++){
  hantei=0;
  rep(j,n){
    if(i<=a[j]){hantei++;}
  }
  rep(k,m){
    if(i>b[k]){hantei++;}
  }
  if(hantei){continue;}
  else{
  cout<<"No War";
  exit(0);
}
}
cout<<"War";
}
