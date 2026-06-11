#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin>>n;

    int64_t m=0,a=0,r=0,c=0,h=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s.at(0)=='M')
          m++;
        else if(s.at(0)=='A')
          a++;
        else if(s.at(0)=='R')
          r++;
        else if(s.at(0)=='C')
          c++;
        else if(s.at(0)=='H')
          h++;
    }

  int64_t cnt=0;
  //5C3=10通りを加算
  //M,A,R
  cnt+=m*a*r;
  //M,A,C
  cnt+=m*a*c;
  //M,A,H
  cnt+=m*a*h;
  //M,R,C
  cnt+=m*r*c;
  //M,R,H
  cnt+=m*r*h;
  //M,C,H
  cnt+=m*c*h;
  //A,R,C
  cnt+=a*r*c;
  //A,R,H
  cnt+=a*r*h;
  //A,C,H
  cnt+=a*c*h;
  //R,C,H
  cnt+=r*c*h;

  cout<<cnt<<endl;

    return 0;
}