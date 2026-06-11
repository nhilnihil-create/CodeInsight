#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
// O(log N)　keyのある場所を返す。なかったら-1を返す
int search(int key, vector<int> a){
  int right = a.size();
  int left = 0;
  while(right >= left){
    int middle = left + (right - left) / 2;
    if(a[middle] == key) return middle; //keyが入ってる場所を返す
    else if(a[middle] > key) right = middle - 1;
    else if(a[middle] < key) left = middle + 1;
  }
  //なければ-1を返す
  return -1;
}
// O(N^2) babble sort
int main(){
  int n;
  cin >> n;
  int f[n][10];
  int p[n][11];
  rep(i, n){
    rep(j, 10){
      cin >> f[i][j];
    }
  }
  rep(i, n){
    rep(j, 11){
      cin >> p[i][j];
    }
  }
  int ans = -10000000 * n;
  for(int check = 1; check < (1 << 10); check++){
    int highScore = 0;
    rep(N, n){
      int cnt = 0;
      rep(j, 10){
        if(((check >> j) & 1) && f[N][j]) cnt++;
      }
      highScore += p[N][cnt];
    }
    ans = (highScore > ans) ? highScore : ans;
  }
  cout << ans << endl;
  return 0;
}