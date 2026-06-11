# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> num, ans;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    x--;
    num.push_back(x);
  }

  for(int i=0; i<n; i++){
    for(int j=num.size()-1; j>=0; j--){
      if(num[j] == j){
        num.erase(num.begin()+j);
        ans.push_back(j+1);
        break;
      }
    }
  }

  if(num.size() != 0){
    ans.clear();
    ans.push_back(-1);
  }
  reverse(ans.begin(), ans.end());
  for(int x : ans) cout << x << endl;

  return 0;
}