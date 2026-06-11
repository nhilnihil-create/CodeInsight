/**
 * auther: moririn_cocoa
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second

int main(void) {
  
  int A;
  int B;
  int C;
  
  cin >> A;
  cin >> B;
  cin >> C;
  
  if ( A == B && B != C ) {
    
    cout << C << endl;
  }
  
  else if ( A == C && A != B ) {
    
    cout << B << endl;
  }
  
  else {
    
    cout << A << endl;
  }
  
  return 0;
}