#include <bits/stdc++.h>
#define r(x,i,n) for(int i = x; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<double> v1(n),v2(n);
  r(0,i,n)cin >> v1.at(i);
  double ave=accumulate(v1.begin(),v1.end(),0.0)/n;
  r(0,i,n){
    v2.at(i)=abs(v1.at(i)-ave);
  }
  auto it=min_element(v2.begin(),v2.end());
  cout << distance(v2.begin(),it) <<endl;
}
