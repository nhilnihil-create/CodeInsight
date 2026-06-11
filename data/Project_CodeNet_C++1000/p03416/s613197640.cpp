#include <bits/stdc++.h>
using namespace std;
int main() {
 int K,N;
 char a[5];
 char b[5];
 int count=0;
 int n,M;
 cin >> K >> N;
  for(int i; i<5 ; i++){
   a[i]=N%10;
   b[i]=K%10;
   K= K/10;
   N= N/10; 
    }
  int AF =10*a[4]+a[3];
  int AB =10*a[1]+a[0];
  int BF =10*b[4]+b[3];
  int BB =10*b[1]+b[0];
  int FA =10*a[3]+a[4];
  int FB =10*b[3]+b[4];  
  
  if(AF==BF){
    if(AB>=FA && BB<= FB){
      n=1;
    }else if(AB>=FA || BB<= FB){
      n=0;
    }else{
      n=-1;
    }
    M= a[2]-b[2]+n;
  }else{
   if(FA>AB){
   count += a[2];
 }else{
   count += a[2]+1;
 }
  if(BB>FB){
    count += 9-b[2];
  }else{
    count += 10-b[2];
  }
    M=(AF-BF-1)*10;
  }   
  cout << count + M << endl;
 }