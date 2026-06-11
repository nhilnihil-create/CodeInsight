#include <bits/stdc++.h>
using namespace std;

 bool is_prime(long long x){
   if(x<=1) return false;
   for(long long i=2;i*i<=x;i++)
   if(x%i==0) return false;
   return true;
 }

int main() {
  int n;
  cin>>n;
  vector<int>sosuu(100005,-1);
  vector<int>hantei(100005,0);
  vector<int>rui(100005,0);
  sosuu[0]=0;
  sosuu[1]=0;
  for(int i=2;i<=100005;i++){
    if(sosuu[i]==-1)sosuu[i]=1;
    if(sosuu[i]==0)continue;
    int count=2;
    while(100005>i*count){
      sosuu[i*count]=0;
      count++;
    }
  }
  for(int i=2;i<100005;i++){
    if(i%2==1 && sosuu[i]==1 && sosuu[(i+1)/2]==1){
      hantei[i]=1;
    }
  }
  for(int i=2;i<100005;i++){
      rui[i]=hantei[i]+rui[i-1];
  }
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    long long kotae=rui[r]-rui[l-1];
    cout<<kotae<<endl;
  }
  return 0;
}
