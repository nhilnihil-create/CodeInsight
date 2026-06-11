#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main (){
 int n,sum_top=0; cin >> n;
 vector<int> top_sum(n),bot(n),bot_sum(n);
 rep(i,n){
   int x; cin >> x;
   sum_top+=x;
   top_sum[i]=sum_top;
 }
 int sum_bot=0;
 rep(i,n){
   cin >> bot[i];
  sum_bot+=bot[i];
 }
 rep(i,n){
   bot_sum[i]=sum_bot;
   sum_bot-=bot[i];
 }

 int ans=0;

  rep(i,n){
    int d =top_sum[i]+bot_sum[i]; 
    ans=max(ans,d);
  }
  cout << ans << endl;

}