#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	int n;cin>>n;
 	vector<int>L(n+1),R(n+1);
 	rep(i,1,n+1){
 		cin>>L[i]>>R[i];
 	}
 	set<pair<pii,int>>st1,st2;
 	rep3(n+1){
 		st1.insert({{L[i],R[i]},i});
 		st2.insert({{R[i],L[i]},i});
 	}
 	int ans=0;
 	int t=0;
 	while(st1.size()>1 && st2.size()>1){
 		auto itr=st1.rbegin();
 		t+=2*itr->x.x;
 		st2.erase({{itr->x.y,itr->x.x},itr->y});
 		st1.erase({{itr->x.x,itr->x.y},itr->y});
 		auto itr2=st2.begin();
 		t-=2*itr2->x.x;
 		st1.erase({{itr2->x.y,itr2->x.x},itr2->y});
 		st2.erase({{itr2->x.x,itr2->x.y},itr2->y});
 		maxs(ans,t);
 	}
 	cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 