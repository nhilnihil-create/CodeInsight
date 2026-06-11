#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  string s; cin >> s;
  int left = 0;
  int right = s.size()-1;
  int ans = 0;
  while (left < right){
    if (s[left] == s[right]){
      left++;
      right--;
    }
    else if (s[left] == 'x'){
      ans++;
      left++;
    }
    else if (s[right] == 'x'){
      ans++;
      right--;
    }
    else{
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
}
