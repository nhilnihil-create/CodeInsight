// my の定義式を修正
// df=0
// int を li に
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define dist(a,b) max((a)-(b),(b)-(a));
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
typedef long int li;

int main(){
  int n,_; cin >>n >>_;
  vector<li> a;

  rep(_,n+1){
    int p; cin >>p;
    a.push_back(p);
  }
  if(df){
    for(const auto &x: a) cout << x << " ";
    cout << "\n";
  } 

  li mx,my,x;
  mx=my=x=dist(a[n],a[n-1]);
  for(int i=n-1; i>=0; i--){
    li d=dist(a[n],a[i]);
    x=max(my,d);
    mx=min(mx,x);
    my=max(my,min(mx,d));
    if(mx==my) {
      d=dist(a[n],a[0]);
      x=max(my,d);
      break;
    }
    if(df)printf("x:%ld mx:%ld my:%ld \n",x,mx,my);
  }
  printf("%ld\n",x);
}
