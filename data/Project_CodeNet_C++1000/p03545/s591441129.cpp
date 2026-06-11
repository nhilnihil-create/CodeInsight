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
  int a, b, c, d;
  a = S[0]-'0';
  b = S[1]-'0';
  c = S[2]-'0';
  d = S[3]-'0';
  int tmp;
  char op[2]={'+', '-'};
  for(int i=0;i<2;++i) {
    for(int j=0;j<2;++j) {
      for(int k=0;k<2;++k) {
        tmp = a;
        if(i==0) tmp += b;
        else tmp -= b;
        if(j==0) tmp += c;
        else tmp -= c;
        if(k==0) tmp += d;
        else tmp -= d;
        if(tmp==7) {
          cout<<a<<op[i]<<b<<op[j]<<c<<op[k]<<d<<"=7"<<endl;
          return 0;
        }
      }
    }
  }
}

