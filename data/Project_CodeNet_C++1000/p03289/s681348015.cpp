#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  bool ok = true;
  if(S[0]!='A') ok = false;
  int cnum = 0;
  for(int i=2;i<S.size()-1;++i) {
    if(S[i]=='C') cnum++;
  }
  if(cnum!=1) ok = false;
  int tmp = 0;
  for(int i=0;i<S.size();++i) {
    if('A'<=S[i] && S[i]<='Z') tmp++;
  }
  if(tmp!=2) ok = false;
  if(ok) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}

