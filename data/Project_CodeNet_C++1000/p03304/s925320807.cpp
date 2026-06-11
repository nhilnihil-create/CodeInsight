        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD =  998244353;

  
     signed main(){
     long double n,m,d;
      cin>>n>>m>>d;
     if(d!=0)cout << std::fixed << std::setprecision(15)<<2*(n-d)*(m-1)/(n*n)<<endl;
     else cout << std::fixed << std::setprecision(15)<<(n-d)*(m-1)/(n*n)<<endl;

      }

        