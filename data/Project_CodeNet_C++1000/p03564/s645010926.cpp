#include<bits/stdc++.h>
using namespace std;
#define REP(i,N) for(int (i)=0;(i)<(N);(i)++)
#define REPR(i,N) for(int (i)=(N);i>=0;i--)
#define FOR (i,m,n) for(int (i)=m;(i)<(n);(i)++)

int main(){
  int all_num, add, ans=1;
  cin >> all_num >> add;

  REP(i,all_num){
    if(ans*2<ans+add) ans*=2;
    else ans+=add;
  }
  cout << ans;
}