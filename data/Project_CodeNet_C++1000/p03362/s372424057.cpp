#include<bits/stdc++.h>
using namespace std;

vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}
int main(){
    int n;
    cin >> n;
    auto t=prime_table(55555);
    int i=0;
    int iter=2;
    while(i<n){
        if(t[iter]==true && iter%5==1){
            cout << iter << " ";
            i++;
        }
        iter++;
    }
    cout << endl;
}