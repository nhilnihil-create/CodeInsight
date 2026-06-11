#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;cin>>n;
  cout<<10-(n/100)<<10-(n%100)/10<<10-(n%10)<<endl;
}