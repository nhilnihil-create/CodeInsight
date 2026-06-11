#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k,count=0;
  cin>>n>>k;  
  int m=n,l=k-n;
     
  for(int i=0;i<k-m+1;i++){  
  int a=n/1000;
  int aaf=a/10,aab=a%10;  
  int af=(n%100)/10,ab=(n%100)%10;    
    n++;
    if(aaf==ab&&aab==af){
      count++;
    }  
  }
  cout<<count<<endl;
  
  
}