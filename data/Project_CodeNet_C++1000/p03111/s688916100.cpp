#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int N,A,B,C;
vector<int> l(N);

int rec(int i,int a, int b, int c) {
  if (i==N) {
    if (!a||!b||!c) return 10000000;
    return abs(a-A) + abs(b-B) + abs(c-C);
  }
  int res = rec(i+1,a,b,c);
  chmin(res, rec(i+1,a+l[i],b,c)+(a?10:0));
  chmin(res, rec(i+1,a,b+l[i],c)+(b?10:0));
  chmin(res, rec(i+1,a,b,c+l[i])+(c?10:0));

  return res;
}

int main() {
  cin >> N >> A >> B >> C;
  l.resize(N);
  rep(i,N) cin >> l[i];
  cout << rec(0,0,0,0) << endl;
}