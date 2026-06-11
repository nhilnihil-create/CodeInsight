#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> g(100001);
int col[1000010];
pair<int, int> tmp;

int main() {
  int n,m;
  cin >> n >>m;
  //priority_queue<int> pq;
  priority_queue< int, vector<int>, greater<int> > pq;
  int a;
  for(int i = 0;i<n;i++){
    cin >>a;
    pq.push(a);
  }

  vector<pair<int, int>> l;
  int b,c;

  for(int i = 0;i<m;i++){
    cin >> b >> c;
    l.push_back({c,b});
    //cout << b << " " << c << endl;
    //cout << l.size() << endl;
  }
  //cout << l[0].second;
  sort(l.begin(), l.end(),greater<pair<int,int> >());
  long long co =0;
  
  for(int i = 0;i<m;i++){
    //cout << l[i].first << " " << l[i].second << endl;
    for(int j =0;j<l[i].second;j++){
      if(l[i].first > pq.top()){
        pq.pop();
        pq.push(l[i].first);
      }else{
        break;
      }
    }
    co += l[i].second;
    if(co > n){
      break;
    }
  }
  
  long long res =0;
  while (!pq.empty()) {
    res += pq.top();
    //cout << pq.top() << endl;
    pq.pop();
  }
  cout << res << endl;
}
