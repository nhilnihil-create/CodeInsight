#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <stack>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int n;
ll a[200020];

bool check(ll k){
  stack<pair<ll,int>> st;
  for(int i=0;i<n-1;i++){
    if(a[i]>=a[i+1]){
      while(st.size()&&st.top().first>a[i+1]){
        st.pop();
      }

      if(st.size()&&st.top().first==a[i+1]){
        st.top().second++;
      }else{
        st.push(make_pair(a[i+1],1));
      }

      while(st.top().second==k){
        ll z=st.top().first;
        if(z==1) return false;

        st.pop();
        if(st.size()&&st.top().first==z-1){
          st.top().second++;
        }else{
          st.push(make_pair(z-1,1));
        }
      }
    }
  }
  return true;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  bool inc=true;
  for(int i=0;i<n-1;i++){
    if(a[i]>=a[i+1]) inc=false;
  }
  if(inc){
    cout<<1<<endl;
    return 0;
  }

  ll l=1,r=n;
  while(r-l>1){
    ll mid=(l+r)/2;
    if(check(mid)) r=mid;
    else l=mid;
  }

  cout<<r<<endl;

  return 0;
}
