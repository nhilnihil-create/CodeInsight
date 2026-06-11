#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X,Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N),y(M);
  for(int i=0;i<N;i++){
    cin >> x.at(i);
  }
  for(int i=0;i<M;i++){
    cin >> y.at(i);
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  if(max(x.back(),X)>=min(y.front(),Y)){
    cout << "War" << endl;
  }else{
    cout << "No War" << endl;
  }
  return 0;
}
