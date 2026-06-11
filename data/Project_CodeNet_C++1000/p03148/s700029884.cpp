#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int n,k;
  cin >> n >> k;

  vector<P> sushi;

  REP(i,n){
    int t,d;
    cin >> t >> d;
    sushi.emplace_back(make_pair(d,t));
  }
  sort(sushi.rbegin(), sushi.rend());

  priority_queue<int, vector<int>, greater<int> > pq;

  set<int> st;
  ll base_score=0;
  REP(i,k){
    base_score+=sushi[i].first;
    if(st.count(sushi[i].second)){
      pq.push(sushi[i].first);
    }else{
      st.insert(sushi[i].second);
    }
  }

  ll score = base_score + st.size() * st.size();

  FOR(i,k,n){
    if(pq.empty())break;
    if(st.count(sushi[i].second))continue;
    base_score -= pq.top();
    pq.pop();
    base_score += sushi[i].first;
    st.insert(sushi[i].second);
    chmax(score, (ll)(base_score + st.size()*st.size()));
  }
  cout << score << endl;
}

