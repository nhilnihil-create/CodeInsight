//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

#define MAX_N 100000000
#define INF 1000000000

int main(){
  long long n,k;
  cin >> n >> k;
  long long t[n],d[n],f[n+1],s[n+1];
  for(int i=0;i<n;i++){
    cin >> t[i] >> d[i];
    f[i] = 0;
    s[i] = 0;
  }
  f[n] = 0;
  s[n] = 0;
  priority_queue<pair<long long, long long> > uneat;
  priority_queue<pair<long long, long long> , vector<pair<long long, long long> >, greater<pair<long long, long long> > > eat;
  for(int i=0;i<n;i++){
    uneat.push(make_pair(d[i],t[i]));
  }
  long long count = 0;
  pair<long long, long long> sushi;

  for(int i=0;i<k;i++){
    sushi = uneat.top();
    eat.push(sushi);
    uneat.pop();
    count += sushi.first;
    s[sushi.second] += 1;
  }

  long long start = 0;
  for(int i=0;i<n+1;i++){
    if(s[i] > 0) start += 1;
  }
  f[start] = count;
  int end = k+1;

  for(int i=start+1;i<k+1;i++){
    while(!eat.empty() && (s[eat.top().second] < 2) ){
      sushi = eat.top();
      eat.pop();
    }
    if(!eat.empty()){
      sushi = eat.top();
      eat.pop();
      f[i] = f[i-1] - sushi.first;
      s[sushi.second] -= 1;
    }
    else{
      end = i;
      break;
    }

    while(!uneat.empty() && (s[uneat.top().second] != 0)){
      sushi = uneat.top();
      uneat.pop();
    }

    if(!uneat.empty()){
      sushi = uneat.top();
      uneat.pop();
      eat.push(sushi);
      f[i] += sushi.first;
      s[sushi.second] += 1;
    }
    else{
      end = i;
      break;
    }
  }

  long long ans = 0;
  for(long long i=start;i<end;i++){
    if(f[i] > 0) ans = max(ans,f[i]+i*i);
  }

  cout << ans << endl;

  return 0;
}
