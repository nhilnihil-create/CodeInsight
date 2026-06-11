#include <bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;

const int N=2e5+5;
const ll INF=1e18;
int a[N];
int main() {
   int n;
   scanf("%d", &n);
   ll sum=0;
   rep(i,n) {
      scanf("%d", &a[i]);
      sum+=a[i];
   }

   // initial first cut at 0
   //         second cut at 1
   //         third cut at 2
   int fi=0, se=1, thi=2;
   ll w=a[0],x=a[1],y=a[2],z=sum-w-x-y;
   ll ans=INF;
   for ( ; se+2<n; se++) {
      // printf("%lld %lld %lld %lld\n", w, x, y, z);
      while ( fi+1<se && abs(w+a[fi+1]-x+a[fi+1])<abs(w-x) ) {
         fi++; w+=a[fi]; x-=a[fi];
      }
      while ( thi+1<n && abs(y+a[thi+1]-z+a[thi+1])<abs(y-z) ) {
         thi++; y+=a[thi]; z-=a[thi];
      }
      ll mx=max({w,x,y,z});
      ll mi=min({w,x,y,z});
      ans=min(ans,mx-mi);
      x+=a[se+1];
      y-=a[se+1];
   }
   printf("%lld\n",ans);
   return 0;
}

