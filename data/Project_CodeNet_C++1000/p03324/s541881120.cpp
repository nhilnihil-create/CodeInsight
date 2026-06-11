#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>	
#include<limits>
#include<ctime>
#include<stack>	
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
	
typedef long long ll;
using namespace std;
const ll x=1000000007;
int mod(ll a){
	return a%x;
}

int main() {
  ll D,N;
  cin >> D >> N ;
  if(N == 100) N = 101;
  if(D == 0) {
    cout << N << endl;
  } else if(D == 1) {
    cout << N*100 << endl;
  } else {
    cout << N*10000 << endl;
  }
  return 0;
}
