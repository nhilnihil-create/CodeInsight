#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000
  signed main(){
    int n;
    int k;
    cin>>n;
    if(n==1){cout<<0;exit(0);}
    vector<int> a(n);
    rep(i,n){
      cin>>k;
      a[i]=k-i-1;
    }
    sort(a.begin(),a.end());
    int s=a.size();
    int c,h;
    if(s%2==1){c=s/2;h=s/2;}
    else{c=s/2;h=s/2-1;}

    int chuuouchi;
    chuuouchi=(a[c]+a[h])/2;

    int ans=0;
    rep(i,n){
      ans+=abs(a[i]-chuuouchi);
    }
  cout<<ans;
 }
