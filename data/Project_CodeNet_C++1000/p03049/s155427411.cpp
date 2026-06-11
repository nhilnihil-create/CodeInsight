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
  int N; cin >> N;
  int ans = 0;
  int num_A = 0;
  int num_B = 0;
  int num_AB = 0;
  rep(i, N){
    string s; cin >> s;
    rep(j, s.size()-1){
      if (s[j] == 'A' && s[j+1] == 'B')ans++;
    }
    if (s[0] == 'B') num_B++;
    if (s[s.size()-1] == 'A') num_A++;
    if (s[0] == 'B' && s[s.size()-1] == 'A') num_AB++;
  }
  int sub;
  if (num_A <= num_AB && num_B <= num_AB && num_AB > 0)sub = 1;
  else sub = 0;
  cout << ans + min(num_A, num_B)-sub << endl;
}