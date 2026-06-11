#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

int main(){
  int N;
  cin >> N;
  int a[N];
  rep(i,N) cin >> a[i];
  int mmax=0;
  int pmax=0;
  int mind, pind;
  rep(i,N){
    if(a[i]<0){
      if(mmax > a[i]){
	mmax=a[i];
	mind=i;
      }
    }
    else if(a[i]>0){
      if(pmax < a[i]){
	pmax=a[i];
	pind=i;
      }
    }    
  }
/*  rep1(i,N-1) {
    if(a[i-1] <= a[i]){
      //      cout << i;
      if(i==N-1){
	cout << 0 << endl;
	return 0;
      }
    }
    else {
      break;
    }
  }*/
  if(mmax==0 && pmax==0){
    cout << 0 << endl;
    return 0;
  }
  //cout << mmax << " " << pmax << endl;
  vector<pair<int, int> > ans;  
  if(abs(mmax) < abs(pmax)){
    rep(i,N){
      if(a[i] < 0){
	ans.pb(mp(pind,i));
	a[i]+=a[pind];
      }
    }
    rep1(i,N-1){
      if(a[i-1] > a[i] ){
	ans.pb(mp(i-1,i));
	a[i]+=a[i-1];
      }
    }
  }
  else{
    rep(i,N){
      if(a[i] > 0){
        ans.pb(mp(mind,i));
	a[i]+=a[mind];
      }
    }
    for(int i=N-1; i>0; i--){
      if(a[i-1] > a[i] ){
	ans.pb(mp(i,i-1));
	a[i-1]+=a[i];
      }
    }
  }
  cout << ans.size() << endl;  
  rep(i,ans.size()){
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << " " << endl;
  }
  
  return 0;

}
