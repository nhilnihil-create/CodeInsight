#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,A,B,C,D;
cin>>N;
A = N/1000;
N=N-A*1000;
B=N/100;
N=N-B*100;
C=N/10;
D=N-C*10;
if(B==C&&(A==B||C==D)){
cout<<"Yes";
}
else{
cout<<"No";
}
}