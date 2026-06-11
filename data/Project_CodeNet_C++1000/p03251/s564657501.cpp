#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  vector<int> p(n);
  vector<int> q(m);
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  for(int i = 0; i < m; i++){
    cin >> q[i];
  }
  int count = *max_element(p.begin(),p.end())+1;
  if(count <= *min_element(q.begin(),q.end()) && x < count && count <= y){
    cout << "No War" << endl;
  }else{
    cout << "War" << endl;
  }
}