#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define rALL(x) x.rbegin(),x.rend()

using namespace std;
using ll=long long;


int main(){
  string u;cin>>u;
  vector<string> s(16);
  s[0]="KIHBR";
  s[1]="KIHBRA";
  s[2]="KIHBAR";
  s[3]="KIHBARA";
  s[4]="KIHABR";
  s[5]="KIHABRA";
  s[6]="KIHABAR";
  s[7]="KIHABARA";

  s[8]="AKIHBR";
  s[9]="AKIHBRA";
  s[10]="AKIHBAR";
  s[11]="AKIHBARA";
  s[12]="AKIHABR";
  s[13]="AKIHABRA";
  s[14]="AKIHABAR";
  s[15]="AKIHABARA";

  for(auto t:s)if(t==u){cout<<"YES";return 0;}
  cout<<"NO";

}