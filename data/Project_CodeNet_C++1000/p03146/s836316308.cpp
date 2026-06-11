# include <bits/stdc++.h>
using namespace std;
int main() {
  int s;
  cin >> s;
  int count = 1;
  while(1) {
    if(s==4||s==2||s==1) {
      cout <<count+3<<endl;
      return 0;
    }
    if(s%2==1) {
      s = 3*s+1;
      count++;
    } else {
      s = s/2;
      count++;
    }
  }
}