        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 1000001;
const int MOD = 1000000007;
   
        signed main() {
           int a,b,c;
          cin>>a>>b>>c;
          if((a<c&&c<b)||(b<c&&c<a))cout<<"Yes";
          else cout<<"No";
           return 0;

        }
