#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a,b,t[10];  
string s;

int main() {
  rep(i,3){
    cin >> a >> b;
    t[a]++,t[b]++;
  }
  if(t[1]>2 || t[2]>2 || t[3]>2 || t[4]>2)
  cout << "NO" << endl;
  else 
  cout << "YES" << endl;
}