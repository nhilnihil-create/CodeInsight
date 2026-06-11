#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
using ll=long long;

long mod=1e9+7;


int main() {
  string s;cin>>s;
  int y=stoi(s.substr(0,4));
  int m=stoi(s.substr(5,2));
  int d=stoi(s.substr(8,2));
  int p=y*10000+m*100+d;
  if(p<=20190430)cout<< "Heisei";
  else cout<<"TBD";
}

