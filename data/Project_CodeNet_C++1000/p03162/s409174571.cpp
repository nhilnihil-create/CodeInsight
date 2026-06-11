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

  vector<vi> nums(n, vi(3));
  fl(0, n)
    cin >> nums[i][0] >> nums[i][1] >> nums[i][2];

  //cout <<"No segmentation faults til here" << endl;

  vector<vi> happ(n, vi(3));
  happ[0][0] = nums[0][0];
  happ[0][1] = nums[0][1];
  happ[0][2] = nums[0][2];

  //cout <<"No segmentation faults til here" << endl;

  fl(1, n){
    for(int j = 0; j < 3; j++){
      int max_hap = 0;
      for (int k = 0; k < 3; k++){
        if(k == j)
          continue;
        int hap = happ[i - 1][k] + nums[i][j];
        max_hap = max(max_hap, hap);
      }
      happ[i][j] = max_hap;
    }
  }

  /*
  fl(0, n){
    cout << happ[i][0] << " " << happ[i][1] << " " << happ[i][2] << "\n";
  }
  */

  int max_hap = max(happ[n - 1][0], happ[n - 1][1]);
  max_hap = max(happ[n - 1][2], max_hap);

  cout << max_hap << "\n";
}