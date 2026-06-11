#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int maxn = 55;
int a[maxn];
int temp[maxn],n,m;

int main(){
  int i,ans=0;
  cin >> n >> m;
  for(i=1;i<=n;i++)
    cin>>a[i];
  for(int l=0;l<=n;l++)
    {
      for(int r=n+1;r>l;r--)
        {
          int cnt=0,sum=0;
          for(i=1;i<=l;i++)
            temp[++cnt]=a[i];
          for(i=n;i>=r;i--)
            temp[++cnt]=a[i];
          if(m<cnt)
            continue;
          sort(temp+1,temp+cnt+1);
          for(i=cnt;i>=0;i--)
            {
              if(i<=m-cnt)
                sum+=max(temp[i],0);
              else
                sum+=temp[i];
            }
          ans=max(ans,sum);
        }
    }
  cout<<ans<<endl;
  return 0;
}
