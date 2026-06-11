#include <bits/stdc++.h>
using namespace std;

int main(){
  const int INF=1e9;
  typedef pair<int,int> P;
  int N,M;
  int out=0;
  cin>>N>>M;
  int l,r,d;
  std::vector<queue<P>> que(N);
  for(int i=0;i<M;i++){
    cin>>l>>r>>d;
    l--;r--;
    que[l].push(P(r,d));
    que[r].push(P(l,d*(-1)));
  }
  queue<int> ank;
  int i;
  int c=0;
  std::vector<int> uu(N,INF);
  while(out==0){
    for(i=0;que[i].size()==0;){
      if(i<N-1)i++;
      else {
        c=1;
        break;
      }
    }
    if(c)break;
    uu[i]=0;
    ank.push(i);
    while(ank.size()){
      int k=ank.front();
      ank.pop();
      while(que[k].size()){
        P w=que[k].front();
        que[k].pop();
        if(uu[w.first]==INF){
          uu[w.first]=uu[k]+w.second;
          ank.push(w.first);
        }
        else{
          if(uu[w.first]!=uu[k]+w.second)out++;
        }
      }
    }
  }
  if(out)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
