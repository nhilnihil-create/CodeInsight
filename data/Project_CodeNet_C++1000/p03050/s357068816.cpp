#include <bits/stdc++.h>
using namespace std;
vector< long long > divisor(long long n) {
  vector< long long > ret;
  for(long long i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) {
          ret.push_back(n / i);
      }
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main(){
    long long n;
    cin >> n;

    long long tmp = n-1;
    long long idx = 2;
    long long res = 0;

    vector<vector<long long>> a(1);

    a[0] = divisor(n);


    for(long long i = 1; i<a[0].size();i++){
        //cout << a[0][i] << " ";
        if(n%(a[0][i]-1) == n/(a[0][i]-1))res+=a[0][i]-1;
    }
    cout << res << endl;
    return 0;
}