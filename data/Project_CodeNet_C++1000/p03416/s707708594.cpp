#include <bits/stdc++.h>
using namespace std;

int main(){

int x,y;
  cin >> x >> y;
  int count=0;
 for(int i=x;i<=y;i++){
 int a=i/10000,b=i%10;
 int c=i/1000%10,d=i%100/10;  
 if(a==b && c==d)count++;
   
 
 }

 cout << count << endl;   
  
  
  


}