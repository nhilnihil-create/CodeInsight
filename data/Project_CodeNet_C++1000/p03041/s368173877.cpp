#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,tuple<int,int,int>> pti;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int N,K;
string s;
int main(){
  cin >> N >> K >> s;
  K--;
  if(s[K]=='A') s[K]='a';
  else if(s[K]=='B') s[K]='b';
  else if(s[K]=='C') s[K]='c';
  cout << s << endl;
}