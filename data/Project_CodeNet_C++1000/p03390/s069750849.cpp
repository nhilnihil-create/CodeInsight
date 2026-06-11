    #include<bits/stdc++.h>
    #define F first
    #define S second
    #define int long long
    #define double long double
    using namespace std;
    typedef pair<int,int> P;
    typedef pair<int,P> iP;
    typedef pair<P,int> Pi;
    typedef pair<P,P> PP;
    double eps=1e-8;
    int mod=1e9+7;
    int inf=1LL<<55;
     
    priority_queue<P,vector<P>,greater<P> > pq;
     
    template <typename T>
    int Count(const vector<T> &v, T l,T r){
      //counting [l,r]
      auto L = lower_bound(v.begin(), v.end(), l );
      auto R = upper_bound(v.begin(), v.end(), r );
      // [l,r) change upper -> lower
      return R-L;
    }
     
    signed main(){
      int q,a,b;
      cin>>q;
      while(q--){
        cin>>a>>b;
        if(a>b)swap(a,b);
        int s=sqrt((double)a*b-1);
        if(s==0){cout<<0<<endl;continue;}
        int mx=(a*b-1)/s;
        int ans=2*s;
        if(mx==s)ans--;
        if(a<=s)ans--;
        //if(b>=mx)p--;
        //  if(s>p-mx)ans--;
        cout<<ans<<endl;
      }
      return 0;
    }