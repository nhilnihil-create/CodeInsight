#include <bits/stdc++.h>
using namespace std;

class Union_Find{
private:
  vector<int64_t> par;
  vector<int64_t> rank;
  vector<int64_t> num;

  int64_t find(int64_t x){
    if(par.at(x)==x){
      return x;
    }else{
      return par.at(x)=find(par.at(x));
    }
  }

public:
  Union_Find(int64_t n){
    par.resize(n);
    rank.resize(n,0);
    num.resize(n,1);
    for(int64_t i=0;i<n;i++){
      par.at(i)=i;
    }
  }

  void unite(int64_t x,int64_t y){
    x=find(x);
    y=find(y);
    if(x==y){
      return;
    }
    if(rank.at(x)<rank.at(y)){
      par.at(x)=y;
      num.at(y)+=num.at(x);
    }else if(rank.at(x)>rank.at(y)){
      par.at(y)=x;
      num.at(x)+=num.at(y);
    }else{
      par.at(x)=y;
      rank.at(y)++;
      num.at(y)+=num.at(x);
    }
  }

  bool same(int64_t x,int64_t y){
    return find(x)==find(y);
  }

  int64_t size(int64_t x){
    return num.at(find(x));
  }

};

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> a(M),b(M);
  for(int i=0;i<M;i++){
    cin >> a.at(i) >> b.at(i);
  }
  int ans=0;
  for(int i=0;i<M;i++){
    Union_Find uf(N+1);
    for(int j=0;j<M;j++){
      if(i==j){
        continue;
      }
      uf.unite(a.at(j),b.at(j));
    }
    if(uf.size(1)!=N){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
