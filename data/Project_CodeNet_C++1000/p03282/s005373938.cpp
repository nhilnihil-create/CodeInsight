#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int main()
{   
    string S;
  int K;
 
  cin >> S;
  cin >> K;
 
  rep(i, K) {
    if(S[i] != '1') {
      cout << S[i];
      return 0;
    }
  }
  cout << '1';
    return 0;
}