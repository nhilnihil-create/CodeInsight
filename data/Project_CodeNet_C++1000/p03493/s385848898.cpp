#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int s;
  cin >>s;
  int s1=s/100;
  int s2=(s-100*s1)/10;
  int s3=s-100*s1-10*s2;
  cout << s1+s2+s3 <<endl;
}