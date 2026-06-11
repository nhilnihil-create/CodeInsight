#include <bits/stdc++.h>
using namespace std;
 

int main() {  
  int N;
  cin>>N;
  vector<int> vect(N+1);
  vector<int> vecx(N+1);
  vector<int> vecy(N+1);
  for(int i=0;i<N;i++){
    cin>>vect.at(i+1)>>vecx.at(i+1)>>vecy.at(i+1);
  }
  bool can =true;
  for(int i=0;i<N;i++){
    int x=vecx.at(i+1)-vecx.at(i);
    int y=vecy.at(i+1)-vecy.at(i);
    int t=vect.at(i+1)-vect.at(i);
    if(abs(x+y)>t) can=false;
    if((t-abs(x+y))%2==1) can=false;
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
       