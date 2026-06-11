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
    string s;cin>>s;
    ll k;cin>>k;
    //just be vigilant about first and second
    ll pos=0;
    for(ll i=0;i<int(s.size());++i){
        if(s[i]!='1'){
            pos=i;break;
        }
    }
    if(k>=pos+1){
        cout<<s[pos];
    }
    else{
        cout<<1;
    }

    
}