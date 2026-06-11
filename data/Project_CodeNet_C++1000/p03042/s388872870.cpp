#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 string S;
 cin>>S;
 string a=S.substr(0,2);
 string b=S.substr(2,2);
 if(a=="00"&&b>="13"){cout<<"NA"<<endl;}
 else if(a>="13"&&b=="00"){cout<<"NA"<<endl;}
 else if(a=="00"&&b=="00"){cout<<"NA"<<endl;}
 else if(a>="13"&&b>="13"){cout<<"NA"<<endl;}
 else if(a>="13"&&b<"13"){cout<<"YYMM"<<endl;}
 else if(a=="00"&&b<"13"){cout<<"YYMM"<<endl;}
 else if(a<"13"&&b>="13"){cout<<"MMYY"<<endl;}  
 else if(a<"13"&&b=="00"){cout<<"MMYY"<<endl;}
 else if(a<"13"&&b<"13"){cout<<"AMBIGUOUS"<<endl;}


 return 0;}