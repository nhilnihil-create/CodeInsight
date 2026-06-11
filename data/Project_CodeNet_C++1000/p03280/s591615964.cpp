#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)

using namespace std;


 int main(){

 int r,c;
 cin>>r>>c;

 int area = 1*c;
 int area1 = 1*r;

 int excu = area+area1-1;

 cout<<r*c-excu<<endl;

 return 0;
 }

