#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  ll sum = 0;
  vector<int> vec(26, 0);
  for(int i=0; i<n; i++){
    vec[str[i]-'a']++;
    ll mul = 1;
    for(int j=0; j<26; j++){
      if(j==str[i]-'a') continue;
      mul *= vec[j]+1;
      mul %= 1000000007;
    }
    sum += mul;
    sum %= 1000000007;
  }
  cout << sum << endl;
  return 0;
}
      
