#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ins insert
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define up_b upper_bound
#define low_b lower_bound
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define rev(i,a,b) for(int i=b;i>=a;i--)
#define boost ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL)
#define nl '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;

const int N=200001;
const int MXN=1000001;
const int inf=1e9;
const ll INF=1e18;

int main(){
  boost;
  int m,k;
  cin>>m>>k;
  if(k==0){
    for(int i=0;i<(1<<m);i++){
      cout<<i<<" "<<i<<" ";
    }
    return 0;
  }

  if(k>=(1<<m)){
    cout<<"-1";
  }
  else if(m==1&&k==1)cout<<"-1";
  else {
    cout<<"0 "<<k<<" 0 ";
    for(int i=1;i<(1<<m);i++){
      if(i!=k)cout<<i<<" ";
    }
    cout<<k<<" ";
    for(int i=(1<<m)-1;i>=1;i--){
      if(i!=k)cout<<i<<" ";
    }
  }
  return 0;
}

