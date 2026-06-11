#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 8020;

int main()
{
  string s;
  cin >> s;
  int x,y;
  cin >> x >> y;

  vector<int> t;
  int cnt = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'T'){
      if(cnt != 0) t.push_back(cnt);
      t.push_back(0);
      cnt = 0;
    }else{
      cnt++;
      if(i == s.size()-1) t.push_back(cnt);
    }
  }

/*
  for(int i = 0; i < t.size(); i++){
    cout << t[i] << " ";
  }printf("\n");
*/
  

  bool dp_x[MAXN][MAXN*2] = {false}, dp_y[MAXN][MAXN*2] = {false};
  dp_x[0][8000] = true;
  dp_y[0][8000] = true;

  bool flag = false;
  bool xy = true; // true -> x
  int cnt_x = 0,cnt_y = 0;
  for(int i = 0; i < t.size(); i++){
    if(t[i] == 0){
      if(!flag) flag = true;
      xy  = !xy;
    }else{
      if(xy){
        cnt_x++;
        //cout << "x =  " << cnt_x <<  endl;
        for(int j = 0; j < MAXN*2; j++){
          if(dp_x[cnt_x-1][j] && j+t[i] < MAXN*2){
            if(j+t[i] < MAXN*2) dp_x[cnt_x][j+t[i]] = true;
            if(j-t[i] >= 0 && flag) dp_x[cnt_x][j-t[i]] = true;
          }
        }
        if(!flag) flag = true;
      }else{
        cnt_y++;
        //cout << "y =  " << cnt_y <<  endl;
        for(int j = 0; j < MAXN*2; j++){
          if(dp_y[cnt_y-1][j] && j+t[i] < MAXN*2){
            if(j+t[i] < MAXN*2) dp_y[cnt_y][j+t[i]] = true;
            if(j-t[i] >= 0) dp_y[cnt_y][j-t[i]] = true;
          }
        }
        if(!flag) flag = true;
      }
    }
  }

  bool is_x = false, is_y = false;
  /*
  for(int j = 0; j < MAXN*2; j++){
    if(dp_x[cnt_x][x+8000]) is_x = true;
  }
  for(int j = 0; j < MAXN*2; j++){
    if(dp_y[cnt_y][y+8000]) is_y = true;
  }
  
  cout << "x =  " << cnt_x <<  endl;
  for(int i = 0; i < MAXN*2; i++){
    if(dp_x[cnt_x][i]) cout << i - 8000 << endl;
  }
  cout << "y = " << cnt_y <<  endl;
  for(int i = 0; i < MAXN*2; i++){
    if(dp_y[cnt_y][i]) cout << i - 8000 << endl;
  }
  */
  if(dp_x[cnt_x][x+8000]) is_x = true;
  if(dp_y[cnt_y][y+8000]) is_y = true;

  if(is_x && is_y) cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}