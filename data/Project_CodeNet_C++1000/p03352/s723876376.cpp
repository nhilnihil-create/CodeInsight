#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define bgn begin()
#define sz size()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>> //小さい順に取り出す
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define all(a)  (a).begin(),(a).end()
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
priority_queue<int> q;
void dfs(int n, int a){
  if(pow(n , a) > 1000)
    return;
  if(a > 12)
    return;
  q.push(pow(n , a));
  dfs(n , a + 1);
}
signed main(){
  int x;
  cin >> x;
  q.push(1);
  for(int i = 2; i < 32; i++){
    dfs(i , 2);
  }
  while(!q.empty()){
    if(q.top() <= x){
      cout << q.top() << endl;
      return 0;
    }
    q.pop();
  }
}