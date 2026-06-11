#include <bits/stdc++.h> 
using namespace std;



int main(){
int N;
  cin >> N;
int min=100000;
  int a,b;
  for(int i=1;i<=N/2;i++){
    
   a=i;
   b=N-i;
    int x=0,y=0;
    while(a>0){
    x+=a%10;
      a/=10;
    }
    while(b>0){
     y+=b%10;
      b/=10;
    }
    
  if(x+y<min)min=x+y;
  }
cout << min << endl;

}