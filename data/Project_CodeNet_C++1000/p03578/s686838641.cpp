#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  int n, m;
  map<int, int> problems;
  vector<int> yosen(m);
  cin >> n;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    problems[num]++;
  }
  cin >> m;
  for(int i=0; i<m; i++){
    int num;
    cin >> num;
    if(problems[num] == 0){
      cout << "NO" << endl;
      return 0;
    }else{
      problems[num]--;
    }
  }
  cout << "YES" << endl;
  return 0;
}
  
  
