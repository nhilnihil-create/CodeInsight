#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
string s;
int w;
cin >> s >> w;
rep(i,s.size()){
  if(i%w==0)cout <<s.at(i);
}
cout << endl;
}
