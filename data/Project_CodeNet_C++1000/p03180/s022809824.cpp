//Om Sree Sai Ram
#include "bits/stdc++.h"
using namespace std;
vector<long long> dp;
vector<long long> val;
long long nax = (long long)1e18 + 5;
//Copied Errichto's code
void recur(int i, const vector<int>& not_taken, long long score_so_far, int mask, int group) {
    if(i == (int) not_taken.size()) {
        dp[mask] = max(dp[mask], score_so_far + val[group]);
        return;
    }
    recur(i + 1, not_taken, score_so_far, mask, group);
    recur(i + 1, not_taken, score_so_far, mask ^ (1 << not_taken[i]),
        group ^ (1 << not_taken[i]));
}

int main() 
{


long long n;
cin>>n;
long long p[n][n];
for(long long i=0;i<n;i++)
{
  for(long long j=0;j<n;j++)
  {
    cin>>p[i][j];
  }
}

val.resize((1<<n));
for(long long i=0;i<val.size();i++)
{
  long long tmp = 0;
  for(long long j=0;j<n;j++)
  {
    for(long long k=j+1;k<n;k++)
    {
      if((1<<j)&i && (1<<k)&i)
      {
        //cout<<"  = "<<i<<" j = "<<j<<endl;
        tmp+=p[j][k];
      } 
    }
  }
val[i] = tmp;
}

//cout<<endl;
dp.assign(1<<n,-nax);
//dp[i] represents maximum value obtained by having exactily i mask
//dp[0] = 0; // base case
// The answer will be at dp.back(); 
dp[0] = 0;
for(int mask=0;mask<val.size();mask++)
{
  vector<int> not_taken;
  for(int i=0;i<n;i++)
  {
    if(!(mask&(1<<i)))
    {
      not_taken.push_back(i);
    }
  }
  recur(0,not_taken,dp[mask],mask,0);
}

cout<<dp.back()<<endl;


}
