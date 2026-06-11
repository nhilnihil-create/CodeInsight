#include<bits/stdc++.h>
using namespace std;
int main(){
  char n;
    int count=0,maxnum=0;
  while(cin >> n){
    if(n=='A' || n=='G' || n=='C' || n== 'T'){
      count++;
      if(maxnum<count)maxnum=count;
    }else count=0;
  }
  cout << maxnum << endl;
}
