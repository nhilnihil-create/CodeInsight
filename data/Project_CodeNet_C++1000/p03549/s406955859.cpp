#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, M;
  cin >> N >> M;  
  cout << (M * 1900 + (N - M) * 100) * pow(2, M) << endl;
}