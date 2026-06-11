#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N);
  rep(i, N){
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  // cout << b[(N+1)/2-1] << " " << b[(N+1)/2] << endl;

  rep(i, N){
    if(a[i] >= b[(N+1)/2]){
      print(b[(N+1)/2-1]);
    } else {
      print(b[(N+1)/2]);
    }
  }
 
}
