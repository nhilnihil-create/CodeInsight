#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
const int LIMIT = 1e9 + 7;
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()

int main(){
	string S;cin>>S;
  int r=0, b=0;

  for(char c: S){
    if(c=='0')r++;
    else b++;
  }

  cout<<min({r,b})*2<<endl;
}