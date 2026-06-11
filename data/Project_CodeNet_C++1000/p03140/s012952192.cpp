#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define sz size()
#define bgn begin()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>>
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define all(a)  (a).begin(),(a).end()

int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
}
signed main(){
  int n;
  cin>>n;
  string a,b,c;
  cin>>a>>b>>c;
  int ans=0;
  fo(i,n){
    V<char> d={a[i],b[i],c[i]};
    Sort(d);
    uni(d);
    if(d.size()==2)
      ans++;
    if(d.size()==3)
      ans+=2;
  }
  cout<<ans<<endl;
}
