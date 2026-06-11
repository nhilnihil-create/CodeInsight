#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  char a[2];
  int x[2];
  cin>>a[0]>>a[1];
  rep(i,2){
    if('A'<=a[i] && a[i]<='F')x[i]=a[i]-'A'+10;
    else x[i]=a[i]-'0';
  }
  if(x[0]<x[1])cout<<"<"<<endl;
  else if(x[0]>x[1])cout<<">"<<endl;
  else cout<<"="<<endl;
  return 0;
}