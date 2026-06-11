#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int m=1000000007;

int main(){
  int n,h;
  cin >> n >> h;
  vi a;
  int mx=0;
  rep(i,n){
    int x,y;
    cin >> x >> y;
    mx=max(mx,x);
    a.push_back(y);
  }
  sort(a.rbegin(),a.rend());
  int cnt=0;
  rep(i,n){
    if(a[i]<=mx){
      break;
    }
    cnt++;
    h-=a[i];
    if(h<=0){cout << cnt; return 0;}
  }
  cnt+=(h-1)/mx+1;
  cout << cnt;
  return 0;
}