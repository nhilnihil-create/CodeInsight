#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
 int A,B,C;
 cin>>A>>B>>C;
 if((3*max({A,B,C})-(A+B+C))%2==0){cout<<(3*max({A,B,C})-(A+B+C))/2<<endl;}
 else{cout<<(3*(max({A,B,C})+1)-(A+B+C))/2<<endl;}
 return 0;}