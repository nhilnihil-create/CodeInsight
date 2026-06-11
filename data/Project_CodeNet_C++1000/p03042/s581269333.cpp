#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  string s;
  cin >> s;
  int f = stoi(s.substr(0, 2));
  int g = stoi(s.substr(2, 2));

  if(f && f < 13){ // mes
	if(g && g < 13)cout << "AMBIGUOUS" << endl;
	else cout << "MMYY" << endl;
  }else{//anio
	if(g && g < 13)cout << "YYMM" << endl;
	else cout << "NA"<< endl;
  }






}


