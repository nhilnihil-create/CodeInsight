#include<iostream>
#include<bits/stdc++.h>

#define fl(k, n) for(int i = k; i < n; i++)
#define flr(k, n) for(int i = n - 1; i >= k; i--)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define mp make_pair
#define ll long long

using namespace std;

int binary_search(vector<int> nums, int target_val){
  int begin = 0;
  int end = nums.size();
  int mid;

  while(begin <= end){
    mid = begin + (end - begin) / 2;
    if(nums[mid] == target_val)
      return mid;
    else if(nums[mid] <= target_val && nums[mid + 1] > target_val)
      return mid;
    else if(nums[mid] > target_val)
      end = mid - 1;
    else
      begin = mid + 1;
  }

  if(begin == 0)
    return -1;
  else 
    return nums.size();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vi heights(n);
  fl(0, n)
    cin >> heights[i];

  vi costs(n);
  costs[0] = 0;
  costs[1] = abs(heights[1] - heights[0]);

  fl(2, n){
    int costj2 = costs[i - 2] + abs(heights[i] - heights[i - 2]);
    int costj1 = costs[i - 1] + abs(heights[i] - heights[i - 1]);
    costs[i] = min(costj2, costj1);
  }

  cout << costs[n - 1] << "\n";

}