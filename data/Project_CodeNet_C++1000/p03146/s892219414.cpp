#include <bits/stdc++.h>
using namespace std;
int main(){
  int s;
  cin >> s;
  int count=1;
  while(s!=1&&s!=2&&s!=4){
    count++;
    if(s%2) s=3*s+1;
    else s/=2;
  }
  cout << count+3 << endl;
}