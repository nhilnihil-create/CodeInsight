#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
  fastIO;
  int n;
  cin >> n;
  if(n == 3){
    cout << "2 5 63\n";
    return 0;
  }
  vector<int> t;
  int sum = 3;
  int id = 6;
  t.push_back(2);
  t.push_back(3);
  t.push_back(4);
  while(t.size() < n){
    if(id % 6 == 0 || id % 6 == 2 || id % 6 == 3 || id % 6 == 4){
      t.push_back(id);
      sum = (sum + id) % 6;
    }
    id++;
  }
  if(sum == 2){
    while(id % 6 != 4){
      id ++ ;
    }
    t[3] = id;
  }
  else if(sum == 3){
    while(id % 6 != 3){
      id ++ ;
    }
    t[3] = id;
  }
  else if(sum == 5){
    if(id % 6 == 4){
      t[1] = id;
    }
    else{
      while(id % 6 != 3){
        id ++ ;
      }
      t[0] = id;
    }
  }
  for(auto x : t)
    cout << x << " ";
  return 0;
}
