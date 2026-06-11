#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
#ifdef ONLINE_JUDGE
#define D(...)
#else
#define D(...)cerr<<__LINE__<<":"<<"["<<#__VA_ARGS__<<"]->",P(__VA_ARGS__)
#endif
void P(){cerr<<endl;} 
template<typename H,typename...T>void P(H h,T...t){cerr<<h<<" ";P(t...);}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(auto &x:v)
        cin>>x;
    sort(all(v));
    int minm=INT_MAX;
    for(int i=0;i+k-1<n;++i){
        minm=min(minm,v[i+k-1]-v[i]);
    }
    cout<<minm;



}