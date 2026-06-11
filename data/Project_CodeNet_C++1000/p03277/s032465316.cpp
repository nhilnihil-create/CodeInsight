    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    const int N=1000006, INF=1000000009;
    long long a[N], b[N], t[200000], n, u;
     
    void upd(int i){ while(i <= 200002) ++t[i], i+=(i&-i); }    
     
    ll sum(int i){
        int x=0;
       	while(i) x+=t[i], i-=(i&-i); 
        return x;
    }     
            
    int main(){ ios_base::sync_with_stdio(false);
        cin>>n;
        for (int i=1; i<=n; i++)
          	cin>>a[i];
        int l=1, r=1e9;
    	ll x=((ll)n*((ll)n+1ll)/(ll)2+(ll)1)/(ll)2;
        while(l<=r){
           	long long mid=(l+r)/2, ans=0, k=100001;
          	for (int i=0; i<=200002; i++)t[i]=0;
           	upd(k);
        	for (int i=1; i<=n; i++)
         		if(a[i]>mid) ans+=sum(k+1), upd(++k);
          		else 		 ans+=sum(k-1), upd(--k);
         	
           	if(ans>=x)l=mid+1;
           	else	  r=mid-1;
        }
        cout<<r+1;
       	return 0;
    }