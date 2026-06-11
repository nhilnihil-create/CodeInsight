        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 1000001;
const int MOD = 1000000007;
   
        signed main() {
          string s;
          cin>>s;
          int ans=0;
          for(int i=0;i<s.size();i++)if(s[i]=='2')ans++;
          cout<<ans;
           return 0;

        }