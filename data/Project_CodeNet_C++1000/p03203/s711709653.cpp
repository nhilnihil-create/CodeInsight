#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

vector<int> ps[200010];

int main(){
  int H,W,N,x,y;
  cin>>H>>W>>N;
  for(int i=0;i<N;i++){
    cin>>x>>y;x--,y--;
    ps[y].push_back(x);
  }
  x=0;
  set<int> ans;
  for(int i=0;i<W;i++){
    sort(all(ps[i]));
    while(find(all(ps[i]),x)!=ps[i].end()){
      x++;
    }
    if(x>=H)break;
    auto it=upper_bound(all(ps[i]),x);
    if(it==ps[i].end()){
      ans.insert(H);
    }else{
      ans.insert(*it);
    }
    x++;
    //cout<<x<<" "<<i<<endl;
  }
  cout<<*ans.begin()<<endl;
}