//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define INF 100000000000000000

int main(){
  long long n;
  cin >> n ;
  long long a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  long long ans = 0;
  long long l = 0,r = 0;
  while(r < n){
    while(r < n && a[l] == a[r]){
      r += 1;
    }
    ans += (r-l)/2;
    l = r;
  }
  cout << ans << endl;

  return 0;
}
