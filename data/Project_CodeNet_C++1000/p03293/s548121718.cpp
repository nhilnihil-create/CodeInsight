
#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
 // c_p_c();
  string a,b;
  cin >> a;
  cin >> b;
  if(a.size() != b.size())
  {
    cout<<"No"<<endl;
  }
  else
  {
      set <char> s1,s2;
      int pos = -1;
    for(int i=0;i<a.size();i++)
    {
      s1.insert(a[i]);
    }
    int t = 0;
    for(int i=0;i<b.size();i++)
    {
      if(b[i] == a[0] && t == 0)
      {
        pos = i;
        t = 1;
      }
      s2.insert(b[i]);
    }
    if(s1 != s2)
    {
      cout<<"No"<<endl;
    }  
    else
    {
      bool ans = false;
      string ts = a + a;
      for(int i = 0;i<ts.size();i++)
      {
        string req = ts.substr(i,a.size());
        if(req == b)
        {
          ans = true;
          break;
        }
      }
      if(ans)
      {
        cout<<"Yes"<<endl;
      }
      else
      {
        cout<<"No"<<endl;
      }
    }
  }
  
  return 0;
}

