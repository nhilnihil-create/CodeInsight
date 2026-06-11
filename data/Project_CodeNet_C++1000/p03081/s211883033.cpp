#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define reps(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   reps(i,0,n)
#define all(x) (x).begin(),(x).end()
#define INF (1000000001)
#define MOD (1000000007)
#define PI (acos(-1))

int N,Q;
string s;
char t[200010],d[200010];

bool outL(int x){//x番目のゴーレムが左からはみ出るか
  if(x>=N+1)return 0;
  rep(i,Q){
    if(s[x] == t[i]){
      if(d[i]=='L')x--;
      else x++;
    }
    if(x==0)return 1;
    if(x==N+1) return 0;
  }
  return 0;
}

bool outR(int x){//右からはみ出るか
  if(x<0)return 0;
  rep(i,Q){
    if(s[x] == t[i]){
      if(d[i]=='L')x--;
      else x++;
    }
    if(x==N+1)return 1;
    if(x==0) return 0;
  }
  return 0;
}

int main(){
  cin >> N >> Q >> s;
  s = " "+s;
  rep(i,Q){
    cin >> t[i] >> d[i];
  }

  int okL=0,ngL=1e9;
  while(abs(ngL-okL)>1){
    int mid = (okL+ngL)/2;
    if(outL(mid)){
      okL = mid;
    }else{
      ngL = mid;
    }
  }

  int okR=N+1,ngR=0;
  while(abs(ngR-okR)>1){
    int mid = (okR+ngR)/2;
    if(outR(mid)){
      okR = mid;
    }else{
      ngR = mid;
    }
  }

  cout << okR-okL-1 << endl;
}