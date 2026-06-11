//Abhinav ---IIIT_A
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>>
#define vi vector<int>
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
ld pie=3.141592653589;
int mod=1e9+7;

bool Compare(pair<int,int> a, pair<int,int> b)
{
    int l1=a.ss-a.ff+1;
    int l2=b.ss-b.ff+1;
    if(l1!=l2) return l1>l2;
    return a.ff > b.ff;
}
std::priority_queue<pii, std::vector<pii>, std::function<bool(pii, pii)>> pq(Compare);

vi vt;

int operation(int a,int b){
  return a+b;
}

void st(int curr,int l,int r,int idx,int val){
  if(l==r){
    if(l==idx) vt[curr]+=val;
    vt[curr]=max(vt[curr],0ll);
    return ;
  }
  int mid=(l+r)/2;
  if(idx>mid) st(2*curr+2,mid+1,r,idx,val);
  else st(2*curr+1,l,mid,idx,val);
  vt[curr]=operation(vt[2*curr+1],vt[2*curr+2]);
}


int gt(int curr,int l,int r,int lx,int rx){
  if(l==r){
    if(l>=lx && l<=rx) return vt[curr];
    return 0;
  }
  if(l>=lx && r<=rx) return vt[curr];
  if(r<lx || l>rx) return 0;
  int mid=(l+r)/2;
  return gt(2*curr+1,l,mid,lx,rx) + gt(2*curr+2,mid+1,r,lx,rx);
}


int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int x,y; cin>>x>>y;
  if(x%y==0) cout<<"-1";
  else cout<<x;
  return 0;
}
// check for overflows dummy !!!
