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
    int n,x;cin>>n>>x;
    int gc;
    for(int i=0,y;i<n;++i){
        cin>>y;
        if(i==0)gc=abs(x-y);
        else
            gc=__gcd(gc,abs(x-y));
    }
    cout<<gc;

    
}