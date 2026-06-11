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
    int n,m,X,Y;
    cin>>n>>m>>X>>Y;
    int maxm=-200;
    for(int i=0,x;i<n;++i){
        cin>>x;
        maxm=max(maxm,x);
    }
    int minm=200;
    for(int i=0,x;i<m;++i){
        cin>>x;
        minm=min(minm,x);
    }
    if(minm>maxm&&Y>=minm&&minm>X){
        cout<<"No War";
    }
    else cout<<"War";
}