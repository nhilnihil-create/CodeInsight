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
    int n;cin>>n;
    double T,A;cin>>T>>A;
    int index=0;
    double ans=1e6;
    for(int i=0;i<n;++i){
        double h;cin>>h;
        double val=T-(.006*h);
        if(fabs(A-val)<ans){
            index=i+1;
            ans=fabs(A-val);
        }
    }
    cout<<index;

}