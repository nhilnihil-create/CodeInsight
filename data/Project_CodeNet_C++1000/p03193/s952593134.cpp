#include<cstdio>
#include<bits/stdc++.h>
typedef long long int ll;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR_IN(i, a, b) for(int i = (a); i < (b); i++)
#define BETWEEN(x, a, b) ((x) >= (a) && (x) <= (b))
#define BIT(b, i) (((b) >> (i)) & 1)
#define LOG_F 1
#define LOG(...) if(LOG_F) fprintf(stderr, __VA_ARGS__)

using namespace std;

ll pow(int x, int n){
  return n == 0 ? 1 : x * pow(x, n - 1);
}


/*
n h w
a1 b1
...
an bn
 */
int n,h,w;

int main(){
  cin>>n>>h>>w;
  int ans=0;
  REP(i,n){
    int a,b;
    cin>>a>>b;
    if(a>=h && b>=w)
      ans++;
  }

  cout<<ans<<endl;

  return 0;
}
