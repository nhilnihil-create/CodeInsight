#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
  cin>>n>>k;
vector<int> tree_height(n);
      for (int i = 0; i <n; i++) {
        cin>> tree_height[i];
    }
      sort(tree_height.begin(), tree_height.end()); 
    reverse(tree_height.begin(), tree_height.end()); 
vector<int> sa(0);
  for(int i=0;i+k-1<n;i++){
    sa.push_back(tree_height[i]-tree_height[i+k-1]);

 }
  sort(sa.begin(),sa.end());
  cout<<sa[0]<<endl;
}
