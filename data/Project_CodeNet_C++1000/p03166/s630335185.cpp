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

void dfs(int curr, vi &in_degree, vector<vi> &edges, vi &dist, vector<bool> &visited){
  visited[curr] = true;
  for(int outv: edges[curr]){
    dist[outv] = max(dist[outv], dist[curr] + 1);
    in_degree[outv]--;
    if(in_degree[outv] == 0){
      dfs(outv, in_degree, edges, dist, visited);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vi> edges(n);
  vi in_degree(n);
  vi dist(n);
  vector<bool> visited(n);
  fl(0, m){
    int inv, outv;
    cin >> inv >> outv;
    inv--;
    outv--;
    edges[inv].push_back(outv);
    in_degree[outv]++;
  }

  fl(0, n){
    if(!visited[i] && in_degree[i] == 0){
      dfs(i, in_degree, edges, dist, visited);
    }
  }

  int max_path = dist[0];
  fl(0, n)
    max_path = max(max_path, dist[i]);

  cout << max_path << "\n";

}