#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n,k;
cin >> n >> k;
vector<int> a(n); 
rep(i,n) cin>> a.at(i);
sort(a.begin(),a.end());

int ans = 1000000000;
rep(i,a.size()-k+1){
  ans = min(a.at(i+k-1)-a.at(i),ans); 
}
cout << ans <<  endl;
}
