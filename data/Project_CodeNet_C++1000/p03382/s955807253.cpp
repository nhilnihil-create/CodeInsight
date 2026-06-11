#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
const ll INF = INT_MAX;


int main() {
  int n;cin >>n;
  vint a(n);
  int maxa=0,maxb=0,maa=0;
  repeat(i,n){
    cin >> a[i];
    maxa = max(maxa,a[i]);
  }
  repeat(i,n){
    if(a[i] == maxa) continue;
    int b;
    if(2*a[i]>maxa){
      b = maxa-a[i];
    }else{
      b = a[i];
    }
    if(maxb < b){
        maxb = b;
        maa = a[i];
    }
  }
  cout << maxa << " " << maa << endl;
  return 0;
}
