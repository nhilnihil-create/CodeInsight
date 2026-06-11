#include <iostream>
#define INT_MAX 1000000
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

int helper(vector<vector<int>>&a, int i, int j, int n, vector<vector<int>>& map)
{
  if (i>=n)
    return 0;
  if (map[i][j])
    return map[i][j];
  int ans = max(ans, j!=0?a[i][0]+helper(a, i+1, 0, n, map):0);
  ans = max(ans, j!=1?a[i][1]+helper(a, i+1, 1, n, map):0); 
  ans = max(ans, j!=2?a[i][2]+helper(a, i+1, 2, n, map):0);
  if (j != -1)
  	map[i][j] = ans;
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(3, 0));
  vector<vector<int>> map(n, vector<int>(3, 0));
  for(int i=0; i<n; i++)
    cin >> arr[i][0]>>arr[i][1]>>arr[i][2];
  cout<<helper(arr, 0, -1, n, map);
  return 0;
}