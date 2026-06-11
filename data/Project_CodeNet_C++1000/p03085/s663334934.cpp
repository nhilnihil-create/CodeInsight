#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
 
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pi;


int main() {
  char b;
  cin >> b;
  map<char, char> mp;
  mp['A'] = 'T';
  mp['T'] = 'A';
  mp['C'] = 'G';
  mp['G'] = 'C';
  cout << mp[b] << endl;
  return 0;
}