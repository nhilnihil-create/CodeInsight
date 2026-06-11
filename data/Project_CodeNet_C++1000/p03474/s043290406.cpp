#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  int A,B;
  string s;
  cin>>A>>B>>s;
  if(s[A]!='-'){
    cout<<"No\n";
    return 0;
  }
  sort(All(s));
  if(s[0]=='-'&&s[1]>='0'&&s[A+B]<='9'){
    cout<<"Yes\n";
  }else cout<<"No\n";

  return 0;
}
