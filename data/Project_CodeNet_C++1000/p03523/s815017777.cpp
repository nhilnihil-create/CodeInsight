
#include <bits/stdc++.h>
 
#define rep(i, n) for (ll i=0;i<(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(x) (x).begin(),(x).end()
 
using namespace std;
//using ll=long long;
typedef long long ll;
typedef pair<ll, ll> pi;

ll h,w;
ll ans;
//vector<char> masu;




int main(){
  string s;
  cin >>s;

  vector<string> S;

  S.push_back("AKIHABARA");
  S.push_back("AKIHABRA");
  S.push_back("AKIHBARA");
  S.push_back("AKIHBRA");

  S.push_back("AKIHABAR");
  S.push_back("AKIHABR");
  S.push_back("AKIHBAR");
  S.push_back("AKIHBR");

  S.push_back("KIHABARA");
  S.push_back("KIHABRA");
  S.push_back("KIHBARA");
  S.push_back("KIHBRA");

  S.push_back("KIHABAR");
  S.push_back("KIHABR");
  S.push_back("KIHBAR");
  S.push_back("KIHBR");

  string a = "NO";
  rep(i, 16){
    
    if(S[i]==s) a = "YES";
  }
  
    
  cout << a <<endl;

  
  
}
