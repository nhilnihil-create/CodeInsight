#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  int a,b;scanf("%d%d",&a,&b);
  double ret=0;
  for(int i=1;i<=a;i++){
    double tmp=1.0/a;
    int now=i;
    while(now<b){
      now*=2;
      tmp/=2;
    }
    ret+=tmp;
  }
  printf("%.12f\n",ret);
}
