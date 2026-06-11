#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>//"M_PI"→円周率(小数点以下5桁)
#include<iomanip>//fixed<<setprecision(15)<<
#define LL long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define E "\n"
#define PI 3.141592653589793


int main(){
  string a;cin>>a;
  int cnt=count(a.begin(),a.end(),'1');
  cout<<cnt<<E;
}