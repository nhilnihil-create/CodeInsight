#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
 int A,B,C,K;
 cin>>A>>B>>C>>K;

 cout<<A+B+C+max({A,B,C})*((1<<K)-1)<<endl;
 return 0;}