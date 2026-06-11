#include <bits/stdc++.h>
using namespace std;

int main() {
  int S,s1,s2,s3;
  cin>>S;
  s1=S/100;
  s2=S/10%10;
  s3=S%2;
  cout<<s1+s2+s3<<endl;
}