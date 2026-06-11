#include "bits/stdc++.h"
#define rep(i,n) for(ll i = 0; i < n; i++)
typedef long long ll;
using namespace std;
#define llMAX c
#define intMAX numeric_limits<int>::max()
#define d_5 100000
#define d9_7 1000000007
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double
#define ll long long
bool order(vector<ll> a){
  rep(i,a.size()-1){
    if(a[i]>a[i+1]){
      return false;
    }
  }
  return true;
}
int main(void){
	ll n;
  cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  vl ans1,ans2;
  int num=0;
  int locmax;
  int locmin;
  ll MAX=numeric_limits<long long>::min();
  ll min=numeric_limits<long long>::max();
  rep(i,n){
    if(MAX<a[i]){
      locmax=i;
      MAX=a[i];
    }
    if(min>a[i]){
      locmin=i;
      min=a[i];
    }
  }
  if((ll)abs(MAX)>=(ll)abs(min)){
    rep(i,n){
      if(i!=locmax){
        a[i]+=a[locmax];
        num++;
        ans1.pb(locmax);
        ans2.pb(i);
      }
    }
    rep(i,n-1){
      num++;
      a[i+1]+=a[i];
      ans1.pb(i);
      ans2.pb(i+1);
    }
  }else{
    rep(i,n){
      if(i!=locmin){
        a[i]+=a[locmin];
        num++;
        ans1.pb(locmin);
        ans2.pb(i);
      }
    }
    rep(i,n-1){

      num++;
      a[n-1-(i+1)]+=a[n-1-i];
      ans1.pb(n-1-i);
      ans2.pb(n-1-(i+1));
    }
  }
  cout<<num<<endl;
  rep(i,num){
    cout<<ans1[i]+1<<" "<<ans2[i]+1<<endl;
  }
	return 0;
}
