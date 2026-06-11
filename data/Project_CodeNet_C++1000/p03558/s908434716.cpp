#include<bits/stdc++.h>
#include<bitset>
#include<random>
#include<time.h>

using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 5e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code



int main()
{
  int k;
  cin>>k;
  vector<pair<int, int>> edge[k];
  for(int i=0; i<k; i++)
  {
    edge[i].pb({(i+1)%k, 1});
    edge[i].pb({(i*10)%k, 0});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<bool> vis(k, false);
  pq.push({1, 1});
  while(!pq.empty())
  {
    int curr, dist;
    pair<int, int> p = pq.top();
    pq.pop();
    curr = p.s;
    dist = p.f;
    if(curr == 0)
    {
      cout<<dist<<endl;
      return 0;
    }
    if(vis[curr] == true) continue;
    vis[curr] = true;
    for(auto np: edge[curr])
    {
      pq.push(make_pair((np.s + dist), np.f));
    }
  }
  return 0;
}
