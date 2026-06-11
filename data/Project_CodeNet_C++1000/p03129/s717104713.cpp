#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
using namespace std;
typedef long long ll;
#define mp make_pair;
#define pb push_back;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N , K;
  cin >> N >> K;

  if((N+1)/2 >= K){
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
  return 0;
    

}
