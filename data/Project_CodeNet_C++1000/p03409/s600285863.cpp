#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>

int main () {
    int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(N);
  vector<int> d(N);
  vector<pair<int,int>> red(N);
  vector<pair<int,int>> blue(N);
  for(int i = 0; i < N; i++){
    cin >> a[i] >> b[i];
    red[i] = make_pair(a[i],b[i]);
  }
 
  for(int i = 0; i < N; i++){
    cin >> c[i] >> d[i];
    blue[i] = make_pair(c[i],d[i]);
  }
 
  int num = 0;
  int ans = 0;
  sort(red.begin(),red.end());
  sort(blue.begin(),blue.end());
  int aka[N],ao[N];
 
  for(int i = 0; i < N; i++){
    aka[i] = 0;
    ao[i] = 0;
  }
  int flag = 0;
  for(int i = 0; i < N; i++){
    flag = 0;
    int max = -1;
    int mita = 0;
    for(int j = 0; j < N; j++){
      if(red[j].first < blue[i].first && red[j].second < blue[i].second && aka[j] == 0 && ao[i] == 0 ){
 
      if(red[j].second > max){ max = red[j].second; flag = j; mita = 1; }
    }
    }
    if(mita == 1){
    aka[flag] = 1;
    ao[i] = 1;
    ans++;
    }
    }
  cout << ans << endl;
    return 0 ;
}

 
