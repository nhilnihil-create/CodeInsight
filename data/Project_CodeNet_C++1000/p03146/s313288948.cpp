#include<bits/stdc++.h>
using namespace std;
int main(){
  int s;
  cin >> s;
  int a[10000100] ={0};
  a[1] += s;
  bool b = false;
  int i = 1;
  while(i < 10000100){
    if(a[i]==4||a[i]==1||a[i]==2){
      cout << i+3 << endl;
      return 0;
    }
    else if(a[i]%2 != 0){
      a[i+1] += 3*a[i]+1;
      i++;
    }
    else{
      a[i+1] += a[i]/2;
      i++;
    }
  }
}

