#include <bits/stdc++.h>
using namespace std;

int N, A, B, C;
int l[100];

int calc(vector<int> v, int target){
  if(v.size()==0) return 1e8;
  int sum=0;
  int cost=10*(v.size()-1);
  for (auto val: v){
    sum+=val;
  }
  cost+=abs(target-sum);
  
  return cost;
}


int dfs (int index, vector<int> a, vector<int> b, vector<int> c){
    if(index==N) {
      return calc(a, A) + calc(b, B) + calc(c, C);
    }
    vector<int> tmp;

    tmp = a;
    tmp.push_back(l[index]);
    int ret1 = dfs(index+1, tmp, b, c);

    tmp = b;
    tmp.push_back(l[index]);
    int ret2 = dfs(index+1, a, tmp, c);
    
    tmp = c;
    tmp.push_back(l[index]);
    int ret3 = dfs(index+1, a, b, tmp);
    
    int ret4 = dfs(index+1, a, b, c);
    
    return min({ret1,ret2,ret3,ret4});
    
}


int main() {
  cin >> N >> A >> B >> C;
  
  for (int i = 0; i < N; i++) {
    cin >> l[i];
  }
  
  vector<int> blank;
  
  cout << dfs(0, blank, blank, blank) << endl;

  return 0;
}
