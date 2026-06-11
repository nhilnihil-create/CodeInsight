#include <bits/stdc++.h>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> P;
vector<int> d;
bool dpx[8005][20005];
bool dpy[8005][20005];
string s;
int x,y,j=0;
int tmp=0;

int main(void)
{
  memset(dpx,false,sizeof(dpx));
  memset(dpy,false,sizeof(dpy));
  cin >> s;
  cin >> x >> y;
  int ssize=int(s.size());
  d.push_back(0);
  for (int i = 0; i < ssize; ++i)
    {
      if(s[i]=='F')
	{
	  d.back()++;
	}
      else if(s[i]=='T') {
	d.push_back(0);
      }
    }
  /*for (int i = 0; i < int(d.size()); ++i)
    {
    cout << d[i] << endl;
    }*/
  int dsize=int(d.size());
  if(d.size()==1)
    {
      if(x==d[0])
	{
	  cout << "Yes" << endl;
	  return 0;
	}
      else
	{
	  cout << "No" << endl;
	  return 0;
	}
    }
  x-=d[0];
  dpx[0][10000]=true;
  dpy[0][10000]=true;
  dpy[1][10000+d[1]]=true;
  dpy[1][10000-d[1]]=true;
  dpx[1][10000]=true;
  for(int j=2;j<dsize;j++)
    {
      for (int i = 0; i <= 20000; ++i)
	{
	  dpx[j][i]=false;
	  if(i+d[j] <= 20000 ) dpx[j][i]|=dpx[j-2][i+d[j]];
	  if(i-d[j] >= 0 ) dpx[j][i]|=dpx[j-2][i-d[j]];
	}
    }

  for(int j=2;j<dsize;j++)
    {
      for (int i = 0; i <= 20000; ++i)
	{
	  dpy[j][i]=false;
	  if(i+d[j] <= 20000 ) dpy[j][i]|=dpy[j-2][i+d[j]];
	  if(i-d[j] >= 0 ) dpy[j][i]|=dpy[j-2][i-d[j]];
	}
    }
  if(dsize&1)
    {
      if(dpx[dsize-1][10000+x] && dpy[dsize-2][10000+y])
	{
	  cout << "Yes" << endl;
	}
      else
	{
	  cout << "No" << endl;
	}
    }
  else
    {
      if(dpy[dsize-1][10000+y] && dpx[dsize-2][10000+x])
	{
	  cout << "Yes" << endl;
	}
      else
	{
	  cout << "No" << endl;
	}
    }
  return 0;
}
