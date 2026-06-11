        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 1000001;
const int MOD = 1000000007;
   
        signed main() {
          int n,h,w,a,b,ans=0;
          cin>>n>>h>>w;
          for(int i=0;i<n;i++){
              cin>>a>>b;
              if(h<=a&&w<=b)ans++;
          }
          cout<<ans;
           return 0;

        }
