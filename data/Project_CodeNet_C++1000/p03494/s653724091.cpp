#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int c=0;
  for(int i=0;i<n;i++){
    int a =0;
    cin >> a;
    int re =0;
    int ord=0;
    while(re==0){
      re = a%2;
      a/=2;
      ord++;
      }
    if (i==0){
      c=ord-1;
        
      }
    else if(c>ord-1){
      c= ord-1;
        
      }
      
    }
  cout << c << endl;
  }
        
       