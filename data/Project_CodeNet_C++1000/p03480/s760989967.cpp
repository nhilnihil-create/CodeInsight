      //In The Name Of GOD
     
    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll ;
    const ll mod = 998244353;
    const ll inf = 2000000000;
    const ll infll = (ll)2*1000*1000*1000*1000*1000*1000;
    const ll maxn = 100*1000+1;
    #define pb push_back
    #define pp pop_back
    #define X first
    #define Y second
    #define IO ios_base::sync_with_stdio(false);
     
    int main(){
      IO;
      string s;
      cin>>s;
      int ans1=s.size(),ans2=s.size();
      for(int  i=0 ;i<s.size();i++){
        if(s[i]=='1'){
          ans1=min(ans1,max(i,(int)s.size()-i-1));
        }
      }
      for(int  i=0 ;i<s.size();i++){
        if(s[i]=='0'){
          ans2=min(ans2,max(i,(int)s.size()-i-1));
        }
      }
      cout<<max(ans1,ans2) ;
    }