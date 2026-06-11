#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

template<class T>
bool chkmax(T & a, T b)
{
  if (a < b){
    a = b;
    return true;
  }
  return false;
}

int l;
int x,y;
int tmp[25],sl=0;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if(fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  scanf("%d ",&l);

  int k=log2(l);

  while(l>0)
  {
    if(l%2==1)
        tmp[++sl]=x;
    x++;
    l/=2;
  }

  printf("%d %d\n",k+1,2*k-1+sl);

  for(int i=1; i<=k; ++i)
  {
    printf("%d %d %d\n",i,i+1,0);
    printf("%d %d %d\n",i,i+1,1<<(i-1));
  }

  y=1<<k;

  for(int i=1; i<sl; ++i)
  {
    printf("%d %d %d\n",tmp[i]+1,k+1,y);
    y+=1<<tmp[i];
  }
}
