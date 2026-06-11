#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

int main(){
  int N;
  cin>>N;
  set<int> ss[1000];

  bool flag=false;

  int n,m;
  for(int i=2;i*(i-1)<=2*N;i++){
    if(i*(i-1)==2*N){
      flag=true;
      n=i;m=i-1;
    }
  }
  if(!flag){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;

  int tmp=1;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=i;j++){
      ss[j].insert(tmp++);
    }
  }

  tmp=1;
  for(int i=2;i<=n;i++){
    for(int j=2;j<=i;j++){
      ss[i].insert(tmp++);
    }
  }
  cout<<n<<endl;
  for(int i=1;i<=n;i++){
    cout<<m<<" ";
    for(auto itr=ss[i].begin();itr!=ss[i].end();++itr){
      cout<<*itr<<" ";
    }
    cout<<endl;
  }
  return 0;
}
