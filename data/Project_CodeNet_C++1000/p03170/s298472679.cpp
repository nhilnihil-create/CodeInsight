#include<iostream>
#include<bits/stdc++.h>

#define fl(k, n) for(int i = k; i < n; i++)
#define flr(k, n) for(int i = n - 1; i >= k; i--)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define mp make_pair
#define ll long long
#define llu long long unsigned int
#define mod 1000000007

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

  int n, k;
  cin >> n >> k;

  vi stones(n);
  fl(0, n)
    cin >> stones[i];

  vector<bool> fp(k + 1);
  fl(0, k + 1){
    for(int a: stones){
      if(i >= a && !fp[i - a])
        fp[i] = true;
    }
  }

  if(fp[k])
    cout << "First\n";
  else
    cout << "Second\n";

}