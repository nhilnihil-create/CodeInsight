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


int32_t main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS



    string s;
    cin >> s;

    vector<int> v;

    for(int i = 0; i < s.size(); i++)
    {
      v.push_back(s[i]-'0');
    }



    for(int mask = 0; mask <= 7; mask++)
    {
     int ans = v[0];
     string ss;

      for(int i = 1; i <= 3; i++)
      {
        if(mask & (1<< (i-1)))
        {
          ans += v[i];
          ss.push_back('+');
        }
        else
        {
          ans -= v[i];
           ss.push_back('-');
        }
      }
     
      if(ans == 7)
      {
        int idx = 0;
        for(int i = 0; i < s.size(); i++)
        {
          cout << s[i];
          if(idx < ss.size())cout << ss[idx++];
        }
        cout << "=7";
        return 0;
      }
    }







    return 0; 
}
