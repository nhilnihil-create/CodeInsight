#include<bits/stdc++.h>
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
    vector<int>v(n);
    for(auto &x:v)
        cin>>x;
    auto it=minmax_element(v.begin(),v.end());
    cout<<*(it.second)-*(it.first)<<endl;



}