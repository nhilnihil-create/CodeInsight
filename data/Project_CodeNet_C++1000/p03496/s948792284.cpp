#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
int s=-1;
int main(){

  int n;cin >> n;
  vector<int> a(n);
  int ab=0;
  int num=0;
  int numi=-1;
  rep(i,n){
    cin >> a[i];
    if(ab<abs(a[i])){
      ab = abs(a[i]);
      num = a[i];
      numi = i+1;
    }
  }
  int ans=0;
  bool flag = false;
  rep(i,n-1) if(a[i]>a[i+1]) flag = true;
  if(flag){
    cout << n-1+n-1 << endl;
    rep(i,n){
      if(i==numi-1){}
      else{
        a[i]+=num;
        cout << numi << " " << i+1 << endl;
      }
    }
    if(a[0]>=0){
      for(int i=1;i<n;i++){
        a[i]+=a[i-1];
        cout << i << " " << i+1 << endl;
      }
    }else{
      for(int i=n-2;i>=0;i--){
        a[i]+=a[i+1];
        cout << i+2 << " " << i+1 << endl;
      }
    }
  }else{
    cout << 0 << endl;
    return 0;
  }
}
