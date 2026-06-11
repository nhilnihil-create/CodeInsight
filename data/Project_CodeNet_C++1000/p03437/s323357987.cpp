#include<iostream>
#include<set>
#include<vector>
using namespace std;

const int MAX_N = 10000000;
bool flag[MAX_N];
typedef long long int ll;

vector<ll> eratosthenes(int n) {
  vector<ll>vec;
  for(int i = 0 ; i < MAX_N ; i++){
    flag[i] = false;
  }
  for(int i = 2 ; i < MAX_N ; i++){
    if(flag[i])continue;
    vec.push_back(i);
    flag[i] = true;
    for(int j = i+i ; j < MAX_N ; j += i){
      flag[j] = true;
    }
  }
  return vec;
}

int main(){
  ll x,y;
  vector<ll> primes = eratosthenes(MAX_N);
  cin >> x >> y;
  if(x % y == 0){
    cout << -1 << endl;
    return 0;
  }
  ll prime = 2;
  for(int i = 0 ; i < primes.size() ; i++){
    if(x % primes[i] != 0 && y % primes[i] != 0){
      prime = primes[i];
      break;
    }
  }
  cout << prime * x << endl;
  return 0;
}
