#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 100000000;
const int MOD = 1000000007;

int main(){
  string s;
  int counter=0;
  std::cin >> s;
  rep(i,s.size())if(s[i]=='x')counter++;
  if(counter>=8)std::cout << "NO" << std::endl;
  else std::cout << "YES" << std::endl;
}