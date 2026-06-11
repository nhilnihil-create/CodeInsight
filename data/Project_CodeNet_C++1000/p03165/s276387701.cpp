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
    
  string s, t;
  cin >> s >> t;

  int n = s.length();
  int m = t.length();

  vector<vi> lcs(n + 1, vi(m + 1));

  fl(0, n + 1)
    lcs[i][0] = 0;

  fl(0, m + 1)
    lcs[0][i] = 0;

  fl(0, n){
    for(int j = 0; j < m; j++){
      if(s[i] == t[j])
        lcs[i + 1][j + 1] = 1 + lcs[i][j];
      else{
        lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
      }
    }
  }

  /*
  fl(0, n + 1){
    for(int j = 0; j <= m; j++){
      cout << lcs[i][j] << " ";
    }
    cout << "\n";
  }
  */


  stack<char> l;
  int im = m;
  int in = n;
  while(im * in != 0){
    // cout << im << " " << in << endl;
    // cout << t[im - 1] << " " << s[in - 1] << endl;
    if(s[in - 1] == t[im - 1]){
      l.push(s[in - 1]);
      in--;
      im--;
    }
    else{
      if(lcs[in][im - 1] > lcs[in - 1][im]){
        im--;
      }
      else{
        in--;
      }
    }
  }

  while(!l.empty()){
    cout << l.top();
    l.pop();
  }
  cout << "\n";
}