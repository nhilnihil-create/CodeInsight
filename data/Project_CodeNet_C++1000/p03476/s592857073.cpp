#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

vector<bool> is_prime() {
  vector<bool>prime(100000, true);
  int n = 100000;
  for(int a = 2; a * a <= n; a++){
    if(!prime[a]) {continue;}
    int b = 2*a;
    while(b <= n) {
      prime[b] = false;
      b += a;
    }
  }
  return prime;
}

vector<int> count(vector<bool>prime) {
  vector<int>numb(100000, 0);
  int n = 100000;
  for(int i = 3; i <= n; i += 2) {
    if(prime[i] && prime[(i+1)/2]) {
      numb[i] = numb[i-2] + 1;
    }
    else {numb[i] = numb[i-2];}
  }
  return numb;
}

int main() {
  int q;
  cin >> q;
  vector<bool>prime(100010, true);
  vector<int>numb(100010, 0);
  prime[0] = false; prime[1] = false;
  prime = is_prime();
  numb = count(prime);
  int max = 1;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    //cout << prime[2017] << endl;
    //cout << numb[5] << endl;
  cout << (numb[r] - numb[l - 2]) << endl;
  }
}