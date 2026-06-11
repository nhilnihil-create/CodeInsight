#include <bits/stdc++.h>

//#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int32_t main() {
    nitin;
    string s;
    cin>>s;
    vector<int>v(26,0);
    for(auto c:s)
    {
        v[c-'a']++;
    }
    bool flag=false;
    char d;
    for(int i=0;i<26;i++)
    {
        d='a'+i;
        if(v[i]==0)
        {
            cout<<s+d<<endl;
            exit(0);
        }
    }
    for(int j=s.length()-1;j>=1;j--)
    {
        if(s[j]>s[j-1])
        {
            vector<char>v;
            for(int k=j;k<s.length();k++)
                if(s[k]>s[j-1])
                v.push_back(s[k]);
              sort(v.begin(),v.end());
              swap(s[j-1],v[0]);
              for(int i=0;i<j;i++)
                  cout<<s[i];
              exit(0);
        }
    }
    cout<<-1<<endl;
    return 0;
}