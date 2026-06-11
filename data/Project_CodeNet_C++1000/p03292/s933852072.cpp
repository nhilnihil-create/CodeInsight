#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define rep(i, n) for(int i=0;i<n;i++)

  
int main(){
 VI a(3);
  cin >> a.at(0) >>a.at(1) >>a.at(2);
 sort(a.begin(),a.end());
  cout << a.at(2)-a.at(0) <<endl;
}
  