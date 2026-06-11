#include<bits/stdc++.h> 
using namespace std; 
typedef  pair<int, int> iPair; 
//#define mod 1000000007
#define pb push_back
typedef long long ll;
typedef long double ld;
#define FOR(i,n) for(i=0;i<n;i++)
#define FORE(i,n) for(i=0;i<=n;i++)
 
 
ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
   
}
    
ll maxl(ll a,ll b){
    if(a>b)return a;
    return b;
}
 
ll minl(ll a,ll b){
    if(a>b)return b;
    return a;
}
 
ll mod = 998244353;
 
ll mulmod(ll a, ll b,ll c){ 
    ll res = 0; 
    a = a % c; 
    while (b > 0){ 
        if (b % 2 == 1){ 
            res = (res + a) % c;
        }
        a = (a * 2) % c; 
        b /= 2; 
    } 
    return res % c; 
}
 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 
 
int a[100005];
int tree[200005];
 
void build(int st,int low,int high){
    if(low==high){
        tree[st] = a[high]%2;
        return;
    }
    int mid = low+(high-low)/2;
    build(2*st,low,mid);
    build(2*st+1,mid+1,high);
    tree[st] = tree[2*st]+tree[2*st+1];
}
 
void update(int st,int start,int end,int ind,int val){
    if(start==end){
        tree[st] = val%2;
        return;
    }
    int mid = start+(end-start)/2;
    if(ind<=mid){
        update(2*st,start,mid,ind,val);
    }
    else update(2*st+1,mid+1,end,ind,val);
    tree[st] = tree[2*st]+tree[2*st+1];
}
 
int query(int st,int start,int end,int low,int high){
    if(start>high || end<low)return 0;
    int mid = start + (end-start)/2;
    if(start==low && end==high){
        return tree[st];
    }
    if(low>mid)return query(2*st+1,mid+1,end,low,high);
    if(high<=mid)return query(2*st,start,mid,low,high);
    return query(2*st,start,mid,low,mid)+query(2*st+1,mid+1,end,mid+1,high);
}

int main()
{
        ios_base::sync_with_stdio(false);
        ll n,k;
        cin >> n >> k;
        map<ll, vector<ll> > m;
        ll ans = 0;
        priority_queue< pair<ll,ll> > pq1;
        priority_queue< pair<ll,ll> > pq2;
        vector<pair<ll,ll> > ord;
        map<ll,ll> count;
        vector<ll> ind(n+1,0);
        for(int i=0;i<n;i++){
            ll t,d;
            cin >> t >> d;
            m[t].pb(d);
        }
        for(auto it = m.begin();it!=m.end();++it){
            sort(it->second.begin(),it->second.end());
            reverse(it->second.begin(),it->second.end());
            pq1.push({it->second[0],it->first});
            ord.pb({it->second[0],it->first});
            count[it->first] = 0;
        }
        sort(ord.begin(),ord.end());
        ll done = 0;
        ll diff = 0;
        while(done<k && !pq1.empty()){
            done++;
            diff++;
            ll t = pq1.top().second;
            ll d = pq1.top().first;
            pq1.pop();
            ans+=d;
            ind[t]++;
            if(ind[t]<m[t].size())pq2.push({m[t][ind[t]],t});
            count[t] = 1;
        }
        while(done<k){
            done++;
            ll t = pq2.top().second;
            ll d = pq2.top().first;
            ans+=d;
            pq2.pop();
            ind[t]++;
            if(ind[t]<m[t].size())pq2.push({m[t][ind[t]],t});
            count[t]++;
        }
        ans+=diff*diff;
        for(int i=0;i<ord.size();i++){
            if(count[ord[i].second]>1)continue;
            else if(count[ord[i].second]==0)continue;
            if(pq2.empty())break;
            ll t = pq2.top().second;
            ll d = pq2.top().first;
            ll t1 = ord[i].second;
            if(d>=m[t1][0]+2*diff-1){
                ans+=d-m[t1][0]-2*diff+1;
                pq2.pop();
                ind[t]++;
                if(ind[t]<m[t].size())pq2.push({m[t][ind[t]],t});
                count[t]++;
                diff--;
            }
        }
        cout << ans << endl;
        return 0;
}