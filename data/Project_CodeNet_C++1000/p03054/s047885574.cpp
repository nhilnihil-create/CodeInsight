#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int H,W,N,a,b;
  string S,T;
  cin>>H>>W>>N>>a>>b>>S>>T;
  a--,b--;
  int mnx=0,mxx=H-1,mny=0,mxy=W-1;
  while(N--){
    if(T[N]=='L')mxy=min(mxy+1,W-1);
    else if(T[N]=='R')mny=max(mny-1,0LL);
    else if(T[N]=='U')mxx=min(mxx+1,H-1);
    else mnx=max(mnx-1,0LL);
    if(S[N]=='L')mny++;
    else if(S[N]=='R')mxy--;
    else if(S[N]=='U')mnx++;
    else mxx--;
    if(mny>mxy || mnx>mxx){
      puts("NO");
      return 0;
    }
  }
  puts(mnx<=a && a<=mxx && mny<=b && b<=mxy?"YES":"NO");
}