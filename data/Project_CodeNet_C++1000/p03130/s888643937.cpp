#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int a[6];
  cin>>a[0]>>a[1]>>a[2];
  cin>>a[3]>>a[4]>>a[5];
  int b[5];
  for(i=0;i<5;i++)b[i]=0;
  for(i=0;i<6;i++)b[a[i]]++;
  sort(b,b+5);
  if(b[1]==1 && b[2]==1 && b[3]==2 && b[4]==2)cout<<"YES";
  else cout<<"NO";
}