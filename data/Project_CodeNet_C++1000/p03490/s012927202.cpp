#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int x_go[16010] = {0};
int y_go[16010] = {0};
int x_go2[16010] = {0};
int y_go2[16010] = {0};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  int x, y;
  cin >> S >> x >> y;

  vector<int> xvec;
  vector<int> yvec;

  S = S + "T";

  int cnt_T = 0;
  int tmp_cnt = 0;
  for(int i = 0; i < S.length(); i++){
    if(S[i] == 'T'){
      if(tmp_cnt > 0){
        if(cnt_T % 2 == 0){
          xvec.push_back(tmp_cnt);
        }else{
          yvec.push_back(tmp_cnt);
        }
      }
      tmp_cnt = 0;
      cnt_T++;
    }else{
      tmp_cnt++;
    }
  }

  int K = 8000;// 0 -> -8000

  // xについて
  if(S[0] == 'T' && xvec.size() > 0){
    x_go[K+xvec[0]] = 1;
    x_go[K-xvec[0]] = 1;
  }else if(S[0] == 'T'){
    x_go[K] = 1;
  }else if(xvec.size() == 0){
    x_go[K] = 1;
  }else{
    x_go[K+xvec[0]] = 1;
  }

  if(yvec.size() == 0){
    y_go[K] = 1;
  }else{
    y_go[K+yvec[0]] = 1;
    y_go[K-yvec[0]] = 1;
  }

  for(int i = 0; i <= 16000; i++){
    x_go2[i] = x_go[i];
    y_go2[i] = y_go[i];
  }
  
  for(int i = 1; i < xvec.size(); i++){
    for(int j = 0; j <= 16000; j++){
      x_go2[j] = 0;
    }
    for(int j = 0; j <= 16000; j++){
      if(x_go[j] == 1){
        if(j+xvec[i] <= 16000){
          x_go2[j+xvec[i]] = 1;
        }
        if(j-xvec[i] >= 0){
          x_go2[j-xvec[i]] = 1;
        }
      }
    }
    for(int j = 0; j <= 16000; j++){
      x_go[j] = x_go2[j];
    }
  }
  
  for(int i = 1; i < yvec.size(); i++){
    for(int j = 0; j <= 16000; j++){
      y_go2[j] = 0;
    }
    for(int j = 0; j <=16000; j++){
      if(y_go[j] == 1){
        if(j+yvec[i] <= 16000){
          y_go2[j+yvec[i]] = 1;
        }
        if(j-yvec[i] >= 0){
          y_go2[j-yvec[i]] = 1;
        }
      }
    }
    for(int j = 0; j <= 16000; j++){
      y_go[j] = y_go2[j];
    }
  }

  if(x_go[K+x] == 1 && y_go[K+y] == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}
