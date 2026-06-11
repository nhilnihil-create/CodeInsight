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
    vector<string>vs;
    for(int i=0;i<n;++i){
        string s;cin>>s;
        if(find(all(vs),s)==vs.end()){
            if(int(vs.size())>0){
                if(vs.back().back()!=s.front())
                    return cout<<"No",0;
            }
            vs.emplace_back(s);
        }
        else
        return cout<<"No",0;
    }
    cout<<"Yes";
    
}