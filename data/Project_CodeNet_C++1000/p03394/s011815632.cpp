#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<int,int> P;
const int mx=30000;
int gcd(ll a, ll b) {if (b==0) return a; else return gcd(b, a%b);}
int main() {
  if (mx!=30000) cerr<<"30003003030303"<<endl;

  int n; cin>>n;
  if (n==3) {cout<<"2 5 63"<<endl; return 0;}
  if (n==4) {cout<<"2 5 20 63"<<endl; return 0;}
  if (n==5) {cout<<"2 5 20 90 63"<<endl; return 0;}
  if (n==6) {cout<<"2 5 20 90 180 63"<<endl; return 0;}

  set<int> v;
  for(int i=1;i*2<=mx;i++) {
    v.insert(i*2);
  }
  for(int i=1;i*3<=mx;i++) {
    v.insert(i*3);
  }
  vector<int> ans;
  if (n%8==7 || n%8==0) {
    int i=0;
    for(int x:v) {ans.push_back(x); if (++i==n) break;}
  } else {
    int m=n/8*8, lf=n-m;
    int i=0;
    for(int x:v) {ans.push_back(x); if (++i==m) break;}
    vector<vector<int>> v1={{29990,29998},{29991,29997},{29992,29996}};
    int idd=0;
    while(lf>0) {
      if (lf>=2) {
        ans.push_back(v1[idd][0]); ans.push_back(v1[idd][1]); lf-=2; idd++;
      } else {
        ans.push_back(29994); lf-=1;
      }
    }
  }
  ll sm=0;
  for(int x:ans) cout<<x<<" "; cout<<endl;
  /*
  vector<bool> u(mx);
  for(int x:ans) sm+=(ll)x;
  for(int x:ans) {
    if (u[x]) cout<<x<<endl;
    u[x]=true;
  }
  for(int x:ans) {
    if (gcd(sm-x,x) == 1) cout<<x<<" "<<sm-x<<endl;
  }*/
}