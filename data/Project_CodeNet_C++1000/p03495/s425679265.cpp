#include <bits/stdc++.h>
#include<iostream>
#define point complex<double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=2e5+10,mod=1e9+7;
ll inf=LONG_LONG_MAX;
int a[N];
int GCD(int a, int b) {
	if(b==0)
    	return a;
	else
    	return GCD(b, a%b);
}



int main()
{
  /* ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
   ll n,k;

   cin>>n>>k;
   map<ll,ll>mp;
   for(int i=0;i<n;i++){
       int x;
   cin>>x;
       mp[x]++;

   }
   vector<ll>val;
   map<ll,ll>::iterator it=mp.begin();
    for(it;it!=mp.end();it++){
            val.push_back(it->second);

       }
       sort(val.begin(),val.end());
   if(val.size()>k){
        ll ans=0;



        for(int i=0;i<val.size()-k;i++){

      ans+=val[i];


       }
    cout<<ans;
    return 0;

   }
   cout<<0;


    return 0;
}
