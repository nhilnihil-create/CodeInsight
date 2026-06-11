#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repe(i,n) for (int i = 0; i <= (n); ++i)

using namespace std;
typedef long long int ll;
int INF = 100100101;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a,b,c,x;
  cin>>a>>b>>c>>x;
  int cnt=0;
  repe(i,a){
   	repe(j,b){
      repe(k,c){
       	int tmp = i*500+j*100+k*50;
        if(tmp == x) cnt++;
      }
    }
  }
  cout << cnt << endl;
}