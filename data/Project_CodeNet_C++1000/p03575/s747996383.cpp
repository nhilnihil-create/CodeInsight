#include<bits/stdc++.h>
using namespace std;
struct Unionfind{
  vector<int>d;
  vector<int>r;
  Unionfind(int n){
    d.resize(n,-1);
    r.resize(n,1);
  }
  
  int find(int x){
     if(d[x]<0) return x;
     else return d[x]=find(d[x]);
  }
  
  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]>r[y]) swap(x,y);
    if(r[x]==r[y]){
       r[y]++;
    }
    d[x]=y;
  }
};

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++){
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
  }
  int bridge=0;
  for(int j=0;j<m;j++){
    Unionfind uf(n);
    bool ok=true;
    for(int i=0;i<m;i++){
      if(i!=j) uf.unite(a[i],b[i]);
    }
    for(int i=0;i<n-1;i++){
        if(uf.find(i)!=uf.find(i+1)) ok=false;
    }
    if(!ok) bridge++;
  }
    cout<<bridge<<endl;
    return 0;
}
