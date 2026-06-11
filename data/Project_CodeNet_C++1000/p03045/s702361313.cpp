#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

// Remove GCC optimizer for codechef
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define int long long
  #define endl "\n"
  #define all(v) v.begin(),v.end()
  #define double long double
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
  const int N = 500005;


int par[N];

void make_set(int n)
{
  for(int i = 0; i <= n; i++)par[i] = i;
}
int getParent(int s)
{
  if(s == par[s])return par[s];
  else return par[s] = getParent(par[s]);
}
void join(int a,int b)
{
  a = getParent(a);
  b = getParent(b);
  if(a != b)par[b] = a;
}

int32_t main()
{



    int n,m;
    cin >> n >> m;

    make_set(n);
    map<int,int> mp;

    for(int i = 1; i<= m; i++)
    {
      int x,y,z;

      cin >> x >> y >> z;
      join(x,y);
    }


    set<int> s;

    for(int i = 1; i <= n; i++)
    {
      s.insert(getParent(i));
    }

    cout << s.size();





    return 0;
}