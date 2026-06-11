#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  if(b-a+1 > k*2) {
    for(int i = a; i < a + k ; i++){
    print(i);
    }
    for(int i = b-k+1; i <= b; i++){
      print(i);
    }
  } else {
    for(int i = a; i <= b; i++){
      print(i);
    }
  }

}
