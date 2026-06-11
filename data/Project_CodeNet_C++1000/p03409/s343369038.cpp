#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> Ryx(n); //<x, y>
  vector<pair<int, int>> Bxy(n); //<y, x>
  REP(i,n){
    cin >> Ryx[i].second >> Ryx[i].first;
  }
  REP(i,n){
    cin >> Bxy[i].first >> Bxy[i].second;
  }
  sort(all(Bxy));
  sort(all(Ryx), greater<pair<int, int>>());
  // cout << "RED" << endl;
  // REP(i,n){
  //   cout << "("<<Ryx[i].second << ", " << Ryx[i].first <<")"<< endl;
  // }
  // cout << "BLUE" << endl;
  // REP(i,n){
  //   cout << "("<<Bxy[i].first << ", " << Bxy[i].second <<")"<< endl;
  // }
  vector<bool> Bseen(n, false);
  int ans = 0;
  int rx, ry;
  int bx, by;
  REP(i,n){
    bx = Bxy[i].first;
    by = Bxy[i].second;
    REP(j,n){
      if(!Bseen[j]){
	rx = Ryx[j].second;
	ry = Ryx[j].first;
	if(rx < bx &&ry < by){
	  ans ++;
	  Bseen[j] = true;
	  // cout << "("<<rx<<","<<ry<< ") <-> ("<<bx<<","<<by<< ")"<< endl;
	  break;
	}
      }
    }
  }
  cout << ans << endl;
}
