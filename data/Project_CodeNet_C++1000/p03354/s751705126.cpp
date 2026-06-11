#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,Z=0;
  cin>>N>>M;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    p.at(i)=a-1;
  }
  vector<vector<int>> G(N);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  vector<int> c(N);
  for(int i=0;i<N;i++){
    if(c.at(i)==0){
      c.at(i)=1;
      queue<int> q;
      vector<int> w;
      vector<int> e;
      q.push(i);
      w.push_back(i);
      e.push_back(p.at(i));
      while(!(q.empty())){
        int a=q.front();
        q.pop();
        for(int x:G.at(a)){
          if(c.at(x)==0){
            c.at(x)=1;
            q.push(x);
            w.push_back(x);
            e.push_back(p.at(x));
          }
        }
      }
      sort(w.begin(), w.end());
      sort(e.begin(), e.end());
      int a=0,b=0;
      while(a<w.size()&&b<e.size()){
        if(w.at(a)>e.at(b)){
          b++;
        }
        else if(w.at(a)<e.at(b)){
          a++;
        }
        else{
          Z++;
          a++;
          b++;
        }
      }
    }
  }
  cout<<Z<<endl;
            
}