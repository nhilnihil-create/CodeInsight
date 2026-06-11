#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int x,y,z;
  x=abs(b-a);
  y=abs(c-b);
  z=abs(c-a);
  bool te=false;
  if(x<=d && y<=d){
    te=true;
  }
  if(z<=d) te=true;
  
  if(te) cout << "Yes" << endl;
  else cout << "No" <<endl;
  

}