  #include <bits/stdc++.h>
  using namespace std;
  long long MOD=1000000007;
  #define IOS() ios_base::sync_with_stdio(0); cin.tie(0);
  typedef long long ll;
  #define pb push_back
  typedef pair<ll,ll> pi;
  double dp[305][305][305];

double solve(int x, int y,int z, int n)
{
  if(x==0 && y==0 && z==0)
    return 0;
  if(x<0 || y<0 || z<0)
    return 0;

  if(dp[x][y][z]>0)
    return dp[x][y][z];

  double exp=n+ x*solve(x-1,y,z,n) + y*solve(x+1,y-1,z,n) + z*solve(x,y+1,z-1,n);
  return dp[x][y][z]=exp/(x+y+z);


}


int main()
{
  IOS();
  memset(dp,-1,sizeof dp);
  int ones=0;
  int two=0;
  int three=0;
  int temp;
  int n;
  cin>>n;
  for (int i = 0; i < n; ++i)
  {
      cin>>temp;
      if(temp==1)
        ones++;
      else if(temp==2)
        two++;
      else
        three++;


  }


  cout<<fixed<<setprecision(12)<<solve(ones,two,three,n)<<endl;

  return 0;
}