#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;
vector<ll> v;
int N;

ll f(ll X, ll A){
  ll ret = X / A;
  return ret * A;
}

ll g(ll X){
  for(int i = 0; i < v.size(); i++){
    X = f(X, v[i]);
  }

  return X;
}

int main(){
  cout << setprecision(10);

  cin >> N;
  v.assign(N,0);
  
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  // 最小をもとめる
  // 2以上で最小
  ll right, left,mid;

  right = 100000000000000000;
  left = 1;
  while(right - left > 1){
    // cerr << left << " " << right << endl;
    mid = (right + left) / 2;
    ll ret = g(mid);
    if(ret >= 2){
      right = mid;
    } else {
      left = mid; 
    }
  }
  ll min_ans = right;

  // 最大を求める
  // 3以上で最小 - 1
  right = 100000000000000000;
  left = 1;
  while(right - left > 1){
    // cerr << left << " " << right << endl;
    mid = (right + left) / 2;
    ll ret = g(mid);
    if(ret >= 3){
      right = mid;
    } else {
      left = mid; 
    }
  }
  ll max_ans = left;

  // cerr << min_ans << " " << max_ans << endl;
  if(min_ans >= max_ans || max_ans < 2 || min_ans < 2){
    cout << -1 << endl;
    return 0;
  }
  cout << min_ans << " " << max_ans << endl;
}
