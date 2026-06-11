/*
  Author: @yash_31
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#define ll long long int
#define eb emplace_back
#define fatafat ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define ft first
#define sd second
#define mkpr make_pair
#define deb(x) std::cout<<#x<<":"<<x<<endl;
#define whole(x) (x).begin(),(x).end()
#define revwhole(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define fbo find_by_order
#define ook order_of_key
#define init0(x) memset(x,0,sizeof(x));

using namespace std; 
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> gharKaSet;
 
const int maxlimit=2e5+2;
const ll inf=1e18;
//TTBDC

vector<ll> ht(maxlimit),score(maxlimit);
vector<ll> sg(4*maxlimit);

ll query(int ql,int qr,int id,int start,int end){
  if(qr<start || end<ql)return 0;
  else if(ql<=start && end<=qr)return sg[id];
  int mid = (start+end)/2;
  return max(query(ql,qr,(id<<1),start,mid),query(ql,qr,(id<<1)+1,mid+1,end));
}

void update(int id,int start,int end,int idx,ll val){
  if(idx<start || end<idx)return;
  else if(idx==start && start==end)sg[id]=val;
  else {
    int mid=(start+end)/2;
    update((id<<1),start,mid,idx,val);
    update((id<<1)+1,mid+1,end,idx,val);
    sg[id]=max(sg[(id<<1)],sg[(id<<1)+1]);
  }
}

int main()
{
  fatafat
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)cin>>ht[i];
  for(int i=1;i<=n;i++)cin>>score[i];
  ll res=-1,curr;
  for(int i=1;i<=n;i++){
    curr = score[i]+query(1,ht[i],1,1,n);
    res=max(res,curr);
    update(1,1,n,ht[i],curr);
  }
  cout<<res;

  return 0;
}