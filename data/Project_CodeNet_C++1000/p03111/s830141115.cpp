#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
#define RAP(i, n) for(ll i=0;i<(n);i++)
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)

#include <iostream>
#include <vector>
using namespace std;

//重複順列
vector<ll> buf;
void permutation(ll i, const ll size, const ll range_start, const ll range_end)
{
    if (i == size) {
      // ここで所望の作業を行う
      for(ll itr:buf){
        cout << itr;
      }
    }
    else{
        for(ll j = range_start; j <= range_end; ++j){
            buf[i] = j;
            permutation(i + 1, size, range_start, range_end);
        }
    }
}
ll mp = 10000, A, B, C, n;
vector<ll> L;
void use_take(ll index, ll a, ll b, ll c, ll mix_num){
  if(index == n && a!=0 && b!=0 && c!=0){
    mp = min(mp, abs(a-A)+abs(b-B)+abs(c-C)+10*mix_num);
  }else if(index < n){
  	use_take(index+1, a, b, c, mix_num);
  	use_take(index+1, a+L[index], b, c, a==0?mix_num:mix_num+1);
  	use_take(index+1, a, b+L[index], c, b==0?mix_num:mix_num+1);
  	use_take(index+1, a, b, c+L[index], c==0?mix_num:mix_num+1);
  }
}
int main(void)
{
  cin >> n >> A >> B >> C;
  L.resize(n);
  RAP(i, n){
    cin >> L[i];
  }
  use_take(0, 0, 0, 0, 0);
  cout << mp << endl;
}
