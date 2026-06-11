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
    vector<int>v(n+1),diff;
    for(auto &x:v)
        cin>>x;
    sort(all(v));
    for(int i=0;i<n;++i){
        diff.emplace_back(v[i+1]-v[i]);
    }
    sort(all(diff));
    for(int i=diff[0];i>=1;--i){
        for(auto x:diff){
            if(x%i!=0)goto label;
        }
        return cout<<i,0;
        label:;
    }


    
}