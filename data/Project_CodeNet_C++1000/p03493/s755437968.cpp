#include <bits/stdc++.h>
using namespace std;

int main() {
  int sss,s1,s2,s3 ;
  cin >> sss;
  s1=sss/100;
  s2=(sss-s1*100)/10;
  s3=sss-s1*100-s2*10;
  //cout <<s1<<endl<<s2<<endl<<s3<<endl;
  cout << s1+s2+s3 <<endl;
}
