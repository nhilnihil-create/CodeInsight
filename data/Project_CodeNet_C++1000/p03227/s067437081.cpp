#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define MOD 1000000007

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF = 1LL << 60;

int main(){
  string s;
  cin >> s;
  if(s.size()==2){
    cout << s  << endl;
  }else{
    reverse(s.begin(),s.end());
    cout << s << endl;
  }
}
