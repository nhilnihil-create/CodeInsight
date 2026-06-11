#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int>a(4);
  char c;
  for(int i=0;i<4;i++){
    cin >> c;
    a.at(i)=c-'0';
  }
  for(int i=0;i<(1<<3);i++){
    bitset<3>n=i;
    int k=a.at(0);
    for(int j=0;j<3;j++){
      if(n.test(j))
        k+=a.at(j+1);
      else
        k-=a.at(j+1);
    }
    if(k==7){
      cout << a.at(0) << (n.test(0)?'+':'-') << a.at(1) << (n.test(1)?'+':'-') << a.at(2) << (n.test(2)?'+':'-') << a.at(3) << "=7\n";
      return 0;
    }
  }
}