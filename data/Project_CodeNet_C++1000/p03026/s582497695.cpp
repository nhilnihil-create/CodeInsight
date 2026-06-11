#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int main(){
  int n;
  cin>>n;
  vector<vector<int>> v(n);
  rep(i,n-1){
    int a,b;cin>>a>>b;
    a--,b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<int> a(n),b(n);
  int c=0;
  rep(i,n){
    cin>>b[i];
    c+=b[i];
  }
  sort(all(b),greater<int>());
  cout<<c-b[0]<<endl;
  queue<int> q;
  q.push(0);
  int cnt=0;
  map<P,bool> m;
  while(!q.empty()){
    int p=q.front();
    q.pop();
    a[p]=b[cnt];
    cnt++;
    for(auto au:v[p]){
      if(!m[P(min(p,au),max(p,au))]){
        q.push(au);
        m[P(min(p,au),max(p,au))]=true;
      }
    }
  }
  rep(i,n){
    cout<<a[i]<<" ";
  }
}