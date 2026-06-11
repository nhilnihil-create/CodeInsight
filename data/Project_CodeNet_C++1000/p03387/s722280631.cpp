#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  vector<ll> alp(3);
  cin >> alp.at(0) >> alp.at(1) >> alp.at(2);

  sort(alp.begin(), alp.end());

  ll maxnum = alp.at(2);
  ll midnum = alp.at(1);
  ll minnum = alp.at(0);

  ll ans_count = 0;

  if( ( maxnum - midnum ) % 2 == 0 && (maxnum - minnum) % 2 == 0){
    ans_count += (maxnum - midnum) / 2 + (maxnum - minnum) / 2;
  }
  else if(( maxnum - midnum ) % 2 != 0 && (maxnum - minnum) % 2 != 0) {
    ans_count++;
    midnum++;
    minnum++;
    ans_count += (maxnum - midnum) / 2 + (maxnum - minnum) / 2;
  }
  else if(( maxnum - midnum ) % 2 == 0 && (maxnum - minnum) % 2 != 0){
    ans_count += (maxnum - midnum) / 2;
    ans_count++;
    maxnum++;
    midnum++;

    ans_count += (maxnum - minnum) / 2;
  }
  else if(( maxnum - midnum ) % 2 != 0 && (maxnum - minnum) % 2 == 0){
    ans_count += (maxnum - minnum) / 2;
    ans_count++;
    maxnum++;
    minnum++;

    ans_count += (maxnum - midnum) / 2;
  }

  cout << ans_count << endl;
}
