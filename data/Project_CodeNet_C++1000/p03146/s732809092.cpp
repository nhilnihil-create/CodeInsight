#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  int count = 4;
  int a = s;
  if(s!=1 && s!= 2 && s!= 4){
   for(count = 5; count < 10000000; count ++){
      if(a%2==0) a=a/2;
      else a=3*a+1;
     
     if(a==4)break;
    }
  }
  
  cout << count << endl;
}