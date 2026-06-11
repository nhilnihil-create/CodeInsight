#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
const ll INF = 1LL<<60;

int main(){
const  ll NUM=41;
  
  ll N,K;
  cin>>N>>K;
ll A[N];
  vector<ll> counter(NUM,0);

  rep(i,N){
     cin>>A[i];
	  bitset<NUM> a(A[i]);  
    rep(j,NUM){
      counter[j]+=a[j];
    }
  }
ll maxbitnum=0;
  bitset<NUM> k(K);
  rep(i,NUM){
    if(k[NUM-1-i]!=0||counter[NUM-1-i]!=0){
      maxbitnum=NUM-1-i;
      break;
    }
  }

  ll ansR=0;
  ll ans=0;
  //ansRの初期化としてX=kを選んだ時
  rep(i,maxbitnum+1){
    ans=ans*2;
    if(k[maxbitnum-i]==0){ans+=counter[maxbitnum-i];}//k=0の時,norで足すのは1の数
    if(k[maxbitnum-i]==1){ans+=N-counter[maxbitnum-i];}//k=1の時,norで足すのは0の数
  }
  //cout<<ans<<endl;
  ansR=ans;
  
  //ansの計算
  rep(i,maxbitnum+1){//上からmaxbitnum-i番目が，k=1なら，x=0にして以下最適解
    ans=0;
    if(k[maxbitnum-i]==0){continue;}//k=0ならスルー
    //ansの計算(maxbitnum-iのみx=0で，それ以下は最適解，それ以上はkに従う
    rep(j,maxbitnum+1){
      ans=ans*2;
		if(maxbitnum-j>maxbitnum-i){//maxbitnum-iより上の桁（kに従う)
  		  if(k[maxbitnum-j]==0){ans+=counter[maxbitnum-j];}//x=0の時,norで足すのは1の数
   		  if(k[maxbitnum-j]==1){ans+=N-counter[maxbitnum-j];}//x=1の時,norで足すのは0の数
        }
		if(maxbitnum-j==maxbitnum-i){//maxbitnum-iの桁（x=0にする)
  		  ans+=counter[maxbitnum-j];//x=0の時,norで足すのは1の数
        }
		if(maxbitnum-j<maxbitnum-i){//maxbitnum-iより小さい桁(最適解)
          ans=ans+max(counter[maxbitnum-j],N-counter[maxbitnum-j]);
        }
    }
    //cout<<ansR<<endl;
    ansR=max(ansR,ans);
  }
  cout<<ansR<<endl;

}
