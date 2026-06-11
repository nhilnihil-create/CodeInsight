#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  tuple<int,int,int>data=make_tuple(0,0,0);
  for(int i=0;i<n;i++){
    int t,x,y;
    cin >> t >> x >> y;
    if((x+y+t)%2==1||abs(t-get<0>(data))<abs(x-get<1>(data))+abs(y-get<2>(data))){
      cout << "No" << endl;
      return 0;
    }
    data=make_tuple(t,x,y);
  }
  cout << "Yes" << endl;
}
