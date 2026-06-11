# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define ll long long

int main(){
 
  int n;
  cin >> n;
  
  vector<int> numbers(n);
  for(int i=0; i<n; i++){
    cin >> numbers[i];
    numbers[i]--;
  }
  
  vector<int> ans;
  while(!numbers.empty()){
    bool flag = false;
    for(int i=numbers.size()-1; i>=0; i--){
      if(numbers[i] == i){
        numbers.erase(numbers.begin()+i);
        ans.push_back(i+1);
        flag = true;
        break;
      }
    }
    
    if(!flag){
      ans.clear();
      ans.push_back(-1);
      break;
    }
  }
  
  reverse(ans.begin(), ans.end());
  for(int num : ans) cout << num << endl;
  
  return 0;
} 

