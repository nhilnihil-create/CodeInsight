#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
vector<llint> vec[6], ans;

int main(void)
{
  cin >> n;
  if(n <= 4){
    ans.push_back(2);
    ans.push_back(5);
    ans.push_back(63);
    if(n == 4) ans.push_back(20);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
    return 0;
  }

  for(int i = 1; i <= 30000; i++) vec[i%6].push_back(i);

  ans.push_back(vec[2][0]);
  ans.push_back(vec[4][0]);
  ans.push_back(vec[3][0]);
  ans.push_back(vec[3][1]);

  vec[2].erase(vec[2].begin());
  vec[4].erase(vec[4].begin());
  vec[3].erase(vec[3].begin());
  vec[3].erase(vec[3].begin());

  n -= 4;

  for(int i = 0; i < vec[2].size() && n >= 2; i++){
    ans.push_back(vec[2][i]);
    ans.push_back(vec[4][i]);
    n -= 2;
  }
  for(int i = 0; i+1 < vec[3].size() && n >= 2; i+=2){
    ans.push_back(vec[3][i]);
    ans.push_back(vec[3][i+1]);
    n -= 2;
  }
  for(int i = 0; i < vec[0].size() && n > 0; i++){
    ans.push_back(vec[0][i]);
    n--;
  }

  for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;

  return 0;
}
