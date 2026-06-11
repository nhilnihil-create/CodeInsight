#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;

int 
main()
{
  int odd = 0;
  vector<pair<int, int>> arr;
  rep(i, 0, 3){
    int tmp; cin >> tmp;
    if(tmp % 2 == 1){
      ++odd;
      arr.push_back({tmp, 1});
    } else{
      arr.push_back({tmp, 0});
    }
  }

  int ans = 0;
  if(odd == 1){
    rep(i, 0, 3){
      if(arr[i].second == 0) arr[i].first += 1;
    }
    ++ans;
  } else if(odd == 2){
    rep(i, 0, 3){
      if(arr[i].second == 1) arr[i].first += 1;
    }
    ++ans;
  }

  int maxi = 0;
  rep(i, 0, 3){
    if(maxi < arr[i].first) maxi = arr[i].first;
  }

  int diff = 0;
  rep(i, 0, 3){
    diff += maxi - arr[i].first;
  }
  ans += diff / 2;
  
  cout << ans << endl;

}