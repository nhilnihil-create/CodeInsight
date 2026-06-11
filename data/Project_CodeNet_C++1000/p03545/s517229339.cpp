#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;

bool f(vector<int> nums, int sum, int i,vector<char> op)
{
  if (i > 3)
  {
    if(sum == 7)
    {
      cout << nums.at(0) << op.at(1) << nums.at(1) << op.at(2)
        << nums.at(2) << op.at(3) << nums.at(3) << "=7" << endl; 
      return true;
    }
    else
    {
      return false;
    }
  }
  op.at(i) = '+';
  if (f(nums, sum + nums.at(i), i + 1, op))
  {
    return true;
  }
  op.at(i) = '-';
  if ( i > 0 && f(nums, sum - nums.at(i), i + 1, op))
  {
    return true;
  }
  return false;
}


int main() {
  string S;
  
  cin >> S;
  vector<int> nums(4);
  vector<char> op(5);
  rep(i, 4)
  {
    nums.at(i) = S.at(i) - '0';
  }
  f(nums,0,0,op);
  
}