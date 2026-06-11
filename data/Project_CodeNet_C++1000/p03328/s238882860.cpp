#include<bits/stdc++.h>
using namespace std;


int main(){
  int a,b;
  cin >> a >> b;
  int sa=b-a;
  int s=0;
  for(int i=1;i<sa;++i){
    s+=i;
  }
  cout << s-a << endl;
  return 0;
}
