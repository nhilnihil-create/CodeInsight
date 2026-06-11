#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bits/stdc++.h>
#include <utility>
#include <iomanip>

#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (a); (b) <= i; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = n; n <= i; i--)
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define elif else if
#define MOD 1000000007
#define INF (1<<29)

using namespace std;

#define ld long double
#define ll long long

map <int ,int> mpa,mpb;
typedef pair<ll, ll> P;
priority_queue<P, vector<P>, greater<P>> pque;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int A,B;
  cin >> A >> B;
  char a[110][110];

  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if(i<50)a[i][j]='.';
      else if(i>=50)a[i][j]='#';
    }
  }

  int cnt=0;
  bool flag=false;
  for(int i=0;i<49;i+=2){
    for(int j=0;j<100;j+=2){
      if(cnt==B-1)flag=true;
      if(flag)break;
      a[i][j]='#';
      cnt++;

      /*if(i%2==0 && j%2==1){
        a[i][j]='#';
        cnt++;
      }else if(i%2==1 && j%2==0){
        a[i][j]='#';
        cnt++;
      }*/
    }
    if(flag)break;
  }

  cnt=0;
  flag=false;
  for(int i=51;i<100;i+=2){
    for(int j=0;j<100;j+=2){
      if(cnt==A-1)flag=true;
      if(flag)break;
      a[i][j]='.';
      cnt++;

      /*if(i%2==0 && j%2==0){
        a[i][j]='.';
        cnt++;
      }else if(i%2==1 && j%2==1){
        a[i][j]='.';
        cnt++;
      }*/
    }
    if(flag)break;
  }
  cout << 100 << " " << 100 << endl;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}