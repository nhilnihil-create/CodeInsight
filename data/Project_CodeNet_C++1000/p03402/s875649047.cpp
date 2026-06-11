#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define tll tuple<ll, ll, ll>
#define all(c) c.begin(),c.end()

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
 
const ll inf = 1000000001;
const ll INF = 1e18;
const ll MOD = 1000000007;

char albt[26] = {'a','b','c','d','e','f','g','h','i','j','k','l',
                 'm','n','o','p','q','r','s','t','u','v','w','x',
                 'y','z'};

//vector<ll> g[202020];
//fill(score, score+202020, 0);
//vector<ll> v;

int main(){
  ll A, B;
  cin >> A >> B;
  ll size = 100;
  
  char G[size][size];
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      if (i < size/2) G[i][j] = '#';
      else if (i >= size/2) G[i][j] = '.';
    }
  }
  
  ll wx = 0;
  ll wy = 0;
  for (int i=1;i<A;i++){
    G[wy][wx] = '.';
    wx += 2;
    if (wx >= size){
      wx = 0;
      wy += 2;
    }
  }
  
  ll bx = 0;
  ll by = size/2 + 1;
  for (int i=1;i<B;i++){
    G[by][bx] = '#';
    bx += 2;
    if (bx >= size){
      bx = 0;
      by += 2;
    }
  }
  
  cout << size << " " << size << endl;
  for (int i=0;i<size;i++){
    for (int j=0;j<size;j++){
      cout << G[i][j];
    }
    cout << endl;
  }
  //cout << ans << endl;
}