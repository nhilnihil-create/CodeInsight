#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
2^20=1048576
使いそう
FMFMFMFMFMFM
とかありうる

5
FMFMV

FMVFV
FMVFM

7
FMFMFMV

2個置きに出るのが続くけど
FMVFMVM

FVFVFVFVとかの可能性もあるわけ
0と1だして、入れ替わってる場所を見つけるとか
でも２回あると戻っちゃう。
7/2=3
0=3=Fだった場合0-3にある
ちがったら4-6にあるとか？
11,5,2

FVFMFMV
1 50000
1 25000 50000 75000
0 2 4 6..
N-2,N-4,... 0

0 3 6として
0==3なら0~3にある
0!=3なら4~6にある？
FMFMFMV

0 2 4
3
個数見て、奇数個かつ同じなら、その中にある
偶数個かつ違うならその中にある？
MVFM
MVMF

FMFMVFM

FMFMFMVFM

FVMFMFMFM=9

FVMFM FMFM 前半部にあるのがわかる
なぜなら、FVFMF MVMF 後半にないといけなくなる
low=0 high=4
FVM 奇数個で違う＝low-midにある

FMFMF MFVMとか
low=4 high=8

FMFVM
mid=6
FMF 
low=6 high=8
いけてそう

FMVFMFM =7

low=0 mid=3 high=6
FMVF
low=0 high=3

うーん、、WA抜けない
なんなんだ


*/
int main(){
  ll N; cin>>N;
  string S;
  char C;
  cout<<0<<endl;
  cin>>S;
  C=S[0];
  ll low=0,high=N-1,mid=(high+low)/2;
  if(C=='V') return 0;
  while(1){
    if(high-low<=3){
      while(low<=high){
        cout<<low<<endl;
        cin>>S;
        if(S[0]=='V') return 0;
        low++;
      }
      return 0;
    }
    cout<<mid<<endl;
    string S; cin>>S;
    if(S[0]=='V') return 0;
    ll m=mid-low+1;//項数
    if(m%2==1){//奇数個で同じFMFならそこにはない
      if(C==S[0])
        low=mid;
      else
        high=mid;
    }
    else{//偶数個
      if(C==S[0])//そこにある
        high=mid;
      else
        low=mid;
    }
    if(low==mid) C=S[0];
    mid=(low+high)/2;
  }
}