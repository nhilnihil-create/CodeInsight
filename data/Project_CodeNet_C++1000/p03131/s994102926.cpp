#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll k, a, b;
int main(){
  cin >> k >> a >> b;
  cout << max(k+1, a+(k-a+1)/2*(b-a)+(k-a+1)%2);
}