#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<tuple<int,int,int>>d[n];
  rep(i,n-1){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    d[a].push_back(tuple<int,int,int>(a,b,c));
    d[b].push_back(tuple<int,int,int>(b,a,c));
  }
  vector<bool>v(n);
  v[0]=true;
  vector<int>ans(n);
  ans[0]=0;
  queue<tuple<int,int,int>>q;
  rep(i,d[0].size()){
    q.push(tuple<int,int,int>(get<0>(d[0][i]),get<1>(d[0][i]),get<2>(d[0][i])));
  }
 
  while(!q.empty()){
    tuple<int,int,int>p=q.front();
    q.pop();
    if(!v.at(get<1>(p))){
      ans.at(get<1>(p))=abs(ans.at(get<0>(p))-get<2>(p)%2);
      v.at(get<1>(p))=true;
      rep(i,d[get<1>(p)].size()){
        if(!v.at(get<1>(d[get<1>(p)][i]))){
          q.push(tuple<int,int,int>(get<0>(d[get<1>(p)][i]),get<1>(d[get<1>(p)][i]),get<2>(d[get<1>(p)][i])));
        }
      }
    }
  }
          
  
  rep(i,n){
    printf("%d\n",ans[i]);
  }
}



