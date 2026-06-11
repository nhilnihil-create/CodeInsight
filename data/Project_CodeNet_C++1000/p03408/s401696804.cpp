#include <bits/stdc++.h>
using namespace std;
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
  const int N = 200005;
int ans;

const int mod = 1000000007;
int cost[101][2];
int32_t main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS

    int n;
    cin >> n;

    vector<string> v1;
    map<string,int> one,two;

    set<string> ss;

    for(int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      v1.push_back(s);
      one[s]++;
      ss.insert(s);
    }


    int m;
    cin >> m;

    vector<string> v2;

    for(int i = 0; i < m; i++)
    {
      string s;
      cin >> s;
      v2.push_back(s);
      two[s]++;
      ss.insert(s);
    }


    for(auto &s : ss)
    {
     
     ans = max(ans,one[s]-two[s]);
    }

    cout << ans;










    return 0; 
}
