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
    string s,t;cin>>s>>t;
    int cnt=s.size();
    while(cnt--){
        if(s==t){
            return cout<<"Yes",0;
        }
        rotate(&s[0],&s[1],&s[int(s.size())]);
    }
    cout<<"No";
    



}