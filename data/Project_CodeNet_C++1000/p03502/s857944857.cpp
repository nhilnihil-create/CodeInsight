#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;

int main() {
 int N;
 cin>>N;
 int x=N;
 int sum=0;
 while(x){
   sum+=x%10;
   x/=10;
 }
 if(N%sum==0){cout<<"Yes"<<endl;}
 else{cout<<"No"<<endl;}
 return 0;  
}