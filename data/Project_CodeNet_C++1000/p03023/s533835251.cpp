#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;

string subsum(int* A,int n,int m){
  bitset<2010> E(1);

  rep(i,0,n){
    E |= (E<<A[i]);
  }

  if(E.test(m)) return "yes";
  else return "no";
}

vector<bool> seen;
vector<int> d;
vector<int> f;
#define pi 3.141592653589793

vector<int64_t> dsy(vector<int64_t>dis,vector<vector<pair<int64_t,int64_t>>> g,int64_t start,int64_t goal){
    int n=dis.size();
    priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> Q;
    dis[start]=0;
    Q.push(make_pair(0,start));

    while(!Q.empty()){
        int pos=Q.top().second;Q.pop();
        for(int i=0;i<g.at(pos).size();i++){
            int to=g.at(pos).at(i).first;
            int cost=g.at(pos).at(i).second;
            if(dis[to]==-1||dis[to]>dis[pos]+cost){
                dis[to]=dis[pos]+cost;
                Q.push(make_pair(dis[to],to));
            }
        }
    }
    return dis;
}


int main(int argc,char **argv){
  int n; cin>>n;
  cout<<180*(n-2)<<endl;
  }