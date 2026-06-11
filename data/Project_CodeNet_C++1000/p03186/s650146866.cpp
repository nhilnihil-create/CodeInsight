#include <iostream>
  #include <algorithm>
  #include <vector>
  #include <cmath>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <iomanip>
  #include <stack>
  #include <queue>
  #include <deque>
  using namespace std;

  int main()
  {
   //   freopen("inverse.in","r",stdin);
   //   freopen("inverse.out","w",stdout);
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      long long a,b,c;
      cin>>a>>b>>c;
      long long ans=0;
      if(c<=b){
          cout<<b+c;
          return 0;
      }
      else{
          ans+=b+b;
          c-=b;
          ans+=min(a+1,c);
          cout<<ans;
          return 0;
      }
      return 0;
}
