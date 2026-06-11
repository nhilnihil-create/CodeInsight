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
    const int base=-2;
    vector<int>v;
    while(n!=0){
        int rem=n%base;
        n/=base;
        if(rem<0){
            rem+=(-base);
            ++n;
        }
        v.emplace_back(rem);
    }
    reverse(all(v));
    if(int(v.size())>0)
    for(auto &x:v)cout<<x;
    else cout<<0;
    
}