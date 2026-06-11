#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,count=0;
  cin >> a;
  count = count + a%10;
  a=a-a%10;
  a=a/10;
  count = count + a%10;
  a=a-a%10;
  a=a/10;
  count = count + a%10;
  cout << count << endl;
}