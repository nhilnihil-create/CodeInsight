#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
/*---------------------DEBUGGING--------------------------------------------*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*-------------------------------------------------------------------------------------*/
//#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pcc pair<char,char>
#define F first
#define S second
#define int long long
#define pi 3.141592653589793238462643383279502
#define M  1000000007
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 10000000000000
#define N 200005
#define vi vector<int>
#define all(v) v.begin(),v.end()
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int a,b,q;
   cin>>a>>b>>q;
   vi shrine,temple;
   rep(i,0,a)
   {
       int x;cin>>x;
       shrine.pb(x);
   }
   rep(i,0,b)
   {
       int x;cin>>x;
       temple.pb(x);
   }
   while(q--)
   {
       int start;
       cin>>start;
       int ans=1e15;
       auto it=lower_bound(all(shrine),start);
       int ans1=0;int ans2=0;
       if(it==shrine.begin())
       {
           ans1+=abs(*(it) - start);
           ans2=ans1;
       }
       else
       {
           it--;
           ans1+=abs(*(it)-start);
           ans2=ans1;
       }
       auto it1=lower_bound(all(temple),start);
       if(it1==temple.begin())
       {
           ans1+=abs(*(it1) - *(it));
           int val=0;
           val+=abs(*(it1)-start);
           val+=abs(*(it1) - *(it));
           ans=min(ans,val);
       }
       else
       {   it1--;
           ans1+=abs(*(it1) - *(it));
           int val=0;
           val+=abs(*(it1)-start);
           val+=abs(*(it1) - *(it));
           ans=min(ans,val);
       }
       ans=min(ans,ans1);
       auto it2=upper_bound(all(temple),start);
       if(it2!=temple.end())
       {
           ans2+=abs(*(it2) - *(it));
           int val=0;
           val+=abs(*(it2)-start);
           val+=abs(*(it2) - *(it));
           ans=min(ans,val);
       }
       else
       {   it2--;
           ans2+=abs(*(it2) - *(it));
           int val=0;
           val+=abs(*(it2)-start);
           val+=abs(*(it2) - *(it));
           ans=min(ans,val);
       }
       ans=min(ans,ans2);
       //debug(ans2);
       int ans3=0,ans4=0;
       it=upper_bound(all(shrine),start);
       if(it!=shrine.end())
       {
           ans3+=abs(*(it) - start);
           ans4=ans3;
       }
       else
       {
           it--;
           ans3+=abs(*(it)-start);
           ans4=ans3;
       }
       auto it3=lower_bound(all(temple),start);
       if(it3==temple.begin())
       {
           ans3+=abs(*(it3) - *(it));
           int val=0;
           val+=abs(*(it3)-start);
           val+=abs(*(it3) - *(it));
           ans=min(ans,val);
       }
       else
       {   it3--;
           ans3+=abs(*(it3) - *(it));
           int val=0;
           val+=abs(*(it3)-start);
           val+=abs(*(it3) - *(it));
           ans=min(ans,val);
       }
       ans=min(ans,ans3);
       auto it4=upper_bound(all(temple),start);
       if(it4!=temple.end())
       {
           ans4+=abs(*(it4) - *(it));
           int val=0;
           val+=abs(*(it4)-start);
           val+=abs(*(it4) - *(it));
           ans=min(ans,val);
       }
       else
       {   it4--;
           ans4+=abs(*(it4) - *(it));
           int val=0;
           val+=abs(*(it4)-start);
           val+=abs(*(it4) - *(it));
           ans=min(ans,val);
       }
       ans=min(ans,ans4);
       cout<<ans<<endl;
   }
}
