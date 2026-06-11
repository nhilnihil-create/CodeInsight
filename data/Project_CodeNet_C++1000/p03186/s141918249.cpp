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
  const long long MAXN=2e6+2;
long long x[2000007];
  unordered_map<long long ,vector <long long> > mp;
  vector<long long> v;
  long long a[MAXN];
  unordered_map<long long,long long > t;
  long long n ;
  void upd(long long x,long long val){
      for(long long i=x;i<=1000000;i=(i|(i+1)))
          t[i]+=val;
  }
  long long get(long long x){
      long long res=0;
      for(long long i=x;i>=0;i=(i&(i+1))-1)
          res+=t[i];
      return res;
  }
  long long getlr(long long l,long long r){
      return get(r)-get(l);
  }
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
