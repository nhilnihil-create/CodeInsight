#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n;
    bool flag=false;
    FOR(i,1,10000){
      if((1+8*n)==i*i && i%2==1){
        flag=true;
        k=(1+i)/2;
        break;
      }
    }
    if(!flag){
      cout<<"No"<<endl;
      return 0;
    }
    cout<<"Yes"<<endl;
    cout<<k<<endl;
    vector<vector<int>> s(k+1);
    int now=1;
    FOR(i,1,k+1){
      int st=now;
      rep(j,k-i){
        s[i].push_back(now++);
      }
      FOR(j,i+1,k+1){
        s[j].push_back(st++);
      }
    }
    FOR(i,1,k+1){
      cout<<k-1<<' ';
      rep(j,k-1) cout<<s[i][j]<<' ';
      cout<<endl;
    }
}