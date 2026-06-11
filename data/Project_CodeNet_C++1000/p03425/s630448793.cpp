#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int N; cin >> N;
  string s;
  map<char,int> c;
  rep(i,N){
    cin >> s;
    if (s[0]=='M' || s[0]=='A' || s[0]=='R'|| s[0]=='C' || s[0]=='H') c[s[0]]++;
  }
  ll retval = 0;
  string march = "MARCH";

  for (int tmp=0;tmp<(1<<5);tmp++){
    bitset<5> s(tmp);
    if (s.count()!=3) continue;
    
    ll cnt = 1;
    rep(i,5){
      if (s.test(i)) cnt *= c[march[i]]; 
    }
    retval += cnt;
  }

  cout << retval << endl;




  // cout << fixed << setprecision(10);
  
  return 0;
}

