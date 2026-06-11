#include <bits/stdc++.h>
using namespace std;

/*
例えばにぶたんを使おうとすると？mより大きいのがいくつあるかが判定出来ればいい
全ての値が4e6以下なのもどうにか使いたいはず
2000回それぞれ4e6を参照してやれば確実に出来る
つまり、dp[i]をiが何回出来るかにしてやれば
dp[0]=1;
for(int i=0;i<N;i++)
  for(int j=4e6;j>=0;j--)
    dp[j+v[i]]+=dp[j];
これで最後に真ん中をみてやればいい（真ん中見るのも大変そうだけど）
けどこれだと8e9回ほどかかる
イメージ的にはdpのコピーを作ってv[i]だけ右にずらして足し合わせるんだよね

*/
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int N;cin>>N;
  vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  int sum=0;
  for(int i=0;i<N;i++)sum+=v[i];
  bitset<4000005> bs(1);
  for(int i=0;i<N;i++)bs|=(bs<<v[i]);
  for(int i=(sum+1)/2;;i++)if(bs[i])fin(i);
}
