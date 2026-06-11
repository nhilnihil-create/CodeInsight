# include <iostream>
# include <vector>
# include <map>
using namespace std;

# define ll long long

bool checkPager(string s, int from, int to){
  for(int i=from; i<to; i++){
    if(s[i] == '#' && s[i+1] == '#') return true;
  }
  return false;
}

bool checkTitik(string s, int from, int to){
  for(int i=from; i<=to; i++){
    if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') return true;
  }
  return false;
}

int main(){
  
  int N, A, B, goalA, goalB;
  cin >> N >> A >> B >> goalA >> goalB;
  N--; A--; B--; goalA--; goalB--;
  
  string s;
  cin >> s;
  
  bool possible = false;
  if(checkPager(s, A, goalA) || checkPager(s, B, goalB)) possible = false;
  else if(goalA < goalB) possible = true;
  else if(checkTitik(s, B, goalB)) possible = true;
  
  cout << (possible ? "Yes" : "No") << endl;
  
  return 0;
} 

