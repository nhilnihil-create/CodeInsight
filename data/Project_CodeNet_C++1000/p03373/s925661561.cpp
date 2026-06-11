#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

int main(){
  int a, b, c, x, y;cin>>a>>b>>c>>x>>y;
  cout<<min(
    (min(x, y)*2*c+abs(x-y)*(x>y?a:b)),
    min(a*x+b*y,max(x, y)*2*c)
  )<<endl;
}
