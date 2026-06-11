#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> p;

int main(){

  int n, t;
  int c, ti;
  //tipo de dato, vector de ese tipo de dato, comparador
  priority_queue<p,vector<p>,greater<p> > q;
  cin >> n >> t;

  for(int i = 0; i < n; i++){
    cin >> c >> ti;
    if(ti <= t){
      q.push(make_pair(c,ti));
    }
  }
 if(q.empty()){
   cout<< "TLE\n";
 }else cout << q.top().first << "\n";

  return 0;
}
