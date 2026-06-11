#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
 int A,B,C,K;
 cin>>A>>B>>C>>K;
 vector<int>k={A,B,C};
 sort(k.begin(),k.end());
 while(K--){
     k[2]*=2;
 }

 cout<<k[0]+k[1]+k[2]<<endl;
 return 0;}