#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
まとめて操作してよさそう
3回
3*A枚用意 3*A/B回換金
2分探索
ああ、ちがいそう
AB無限ループできるのか
2ターン換金操作をするので、差がB-A<=2ならK+1か
そうじゃない場合。
まずA枚ためて、そこからずっとBAループ
お金が余らないように最後調整
基本的にすぐ換金が考えやすいか

2 5
K bis money
1 2   0
2 0   1
3 5   0
4 3   1
5 8   0
6 6   1
7 11  0
-A+B-A+B-A+B-A+...+Bでおわるか、+1でおわるか。
*/
int main(){
  ll K,A,B,bis=1; cin>>K>>A>>B;
  if(B-A<=2 || K<=A){
    cout<<K+1<<endl;
    return 0;
  }
  K-=A-1;
  bis=A;
  if(K%2==0)//Bでおわる
    bis+=B*(K/2)-A*(K/2);
  else
    bis+=B*(K/2)-A*(K/2)+1;
  cout<<bis<<endl;
}