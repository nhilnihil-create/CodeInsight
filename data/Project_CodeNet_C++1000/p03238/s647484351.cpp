#include <iostream>
#include <map>
#include <vector>
using namespace std; using P=pair<int,int>; using ll=long long;
struct tp {int x,y,i; bool operator<(const tp tt) const {if (x==tt.x) return y<tt.y; else return x<tt.x;}};

int main() {
  int n; cin>>n;
  if (n==1) cout<<"Hello World"<<endl;
  else {
    int a,b; cin>>a>>b;
    cout<<a+b<<endl;
  }
}