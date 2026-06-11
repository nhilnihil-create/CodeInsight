#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,cnt=0;
  cin >> n;
  for(int i=1;i<n;i+=2){
    int count=0;
    for(int j=1;j<=i;j+=2){
      if(i%j==0)count++;
    }
    if(count==8)cnt++;
  }
 if(n%2==1){
   int count=0;
   for(int i=1;i<=n;i+=2){
     if(n%i==0)count++;
   }
   if(count==8)cnt++;
 }
  cout << cnt << endl;
}