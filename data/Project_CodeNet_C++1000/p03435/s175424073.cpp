#include<bits/stdc++.h>
//cervello|Phoenix
using namespace std;
#define ll long long int
#define eb emplace_back
#define mk make_pair
#define all(x) x.begin(),x.end()
#define mod 1000000007

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int> > grid(3, vector<int> (3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      cin>>grid[i][j];
    grid[i][1]-=grid[i][0], grid[i][2]-=grid[i][0], grid[i][0]=0;
  }

  for(int i=0;i<3;i++)
    if(!(grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i]))
      return cout<<"No\n", 0;

  cout<<"Yes\n";
  return 0;
}