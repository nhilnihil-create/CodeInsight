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
  string s;
  cin >> s;
  int a[3] = {0};
  a[s[0]-'a']++;
  a[s[1]-'a']++;
  a[s[2]-'a']++;

  if(a[0]==a[1] && a[1]==a[2]) print("Yes");
  else print("No");
}
