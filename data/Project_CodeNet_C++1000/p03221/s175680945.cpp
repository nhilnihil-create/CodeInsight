#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> a(m,vector<int>(3));
  rep(i,m){
    int x,y;
    cin >> x >> y;
    a[i][0]=x;
    a[i][1]=y;
    a[i][2]=i;
  }
  sort(a.begin(),a.end());
  int checker=a[0][0],cnt=0;
  rep(i,m){
    cnt++;
    if(a[i][0]==checker){
      a[i][1]=cnt;
    }else{
      checker=a[i][0];
      a[i][1]=1;
      cnt=1;
    }
    swap(a[i][0],a[i][2]);
  }
  sort(a.begin(),a.end());
  rep(i,m){
    printf("%06d", a[i][2]);
    printf("%06d\n", a[i][1]);
  }
  
  return 0;
}