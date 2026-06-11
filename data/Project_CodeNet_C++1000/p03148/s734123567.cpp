#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
   FAST/**/
   
   ll n,k;
   cin>>n>>k;
   
   pair<ll,ll> arr[n];
   ll dist = 0;
   unordered_map<ll,ll> ma;
   for(ll i=0;i<n;i++)
   {
       cin>>arr[i].second>>arr[i].first;
       arr[i].second--;
       ma[arr[i].second] = 1;
   }
   
   dist = ma.size();
   
   sort(arr,arr+n,greater<pair<ll,ll>>());        
   
   ll mcost[n];
   memset(mcost,-1,sizeof(mcost));
   
   for(ll i=0;i<n;i++)
        mcost[arr[i].second] = max(arr[i].first,mcost[arr[i].second]);
   
   unordered_map<ll,ll> mark;
   ll ans = 0;
   for(ll i=0;i<k;i++)
        ans+=arr[i].first, mark[arr[i].second]++;  
   
   ll ans1 = ans;
   
   ans+=mark.size()*mark.size();
   //cout<<"ans = "<<ans<<"\n";
   ll cnt = mark.size();
   
   multiset<pair<ll,ll>> st;
   set<pair<ll,ll>, greater<pair<ll,ll>>> res;
   for(ll i=0;i<k;i++)
   {
        st.insert(mp(arr[i].first,arr[i].second));
   }
   
   for(ll i=0;i<n;i++)
   {
       if(mark[i] == 0 && mcost[i]>-1)
            res.insert(mp(mcost[i],i));
   }
   
   while(cnt<min(k,dist))
   {
       while(st.size() > 0 && mark[st.begin()->second] < 2)
            st.erase(st.begin());
        auto it = st.begin();
        mark[it->second]--;
        ans1-=it->first;
        
        st.erase(st.begin());
        mark[res.begin()->second] = 1;
        ans1+=res.begin()->first;
        //st.insert(*res.begin());
        res.erase(res.begin());
        cnt++;
        
        ans = max(ans,ans1+cnt*cnt);
   }
   
   cout<<ans;
   
               
        
   return 0;
}