#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=61
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int H,W;
  cin>>H>>W;
  int h,w;
  cin>>h>>w;
  cout<<H*W-h*W-H*w+h*w<<endl;
}