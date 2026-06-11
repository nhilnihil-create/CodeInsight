#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> leftVec(26, 0);
  vector<int> rightVec(26, 0);
  rep(i, n) rightVec[str[i]-'a']++;
  int biggest = 0;
  rep(i, n){
    rightVec[str[i]-'a']--;
    leftVec[str[i]-'a']++;
    int cnt = 0;
    rep(j, 26){
      if(leftVec[j] != 0 && rightVec[j] != 0) cnt++;
    }
    biggest = max(biggest, cnt);
  }
  cout << biggest << endl;
  return 0;
}
        
      
      
      
      
      
      
      
  