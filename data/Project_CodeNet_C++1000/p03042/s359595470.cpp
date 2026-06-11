#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int S;
 cin>>S;
 int a=S/100;
 int b=S%100;
 if(a>=1&&a<=12){if(b>=1&&b<=12){cout<<"AMBIGUOUS"<<endl;}
                 else{cout<<"MMYY"<<endl;}}
 else{if(b>=1&&b<=12){cout<<"YYMM"<<endl;}
      else{cout<<"NA"<<endl;}}


 return 0;}