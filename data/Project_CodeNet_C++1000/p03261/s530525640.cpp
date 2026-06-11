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
    int flag=0;
    string s;
    char mark;
    unordered_set<string>st;
    while(cin>>s){
        if(flag==0){
            mark=s.back();
            flag=1;
        }
        else
        {
            if(s.front()!=mark){
                return cout<<"No",0;
            }
            mark=s.back();
        }
        st.insert(s);
    }
    if(int(st.size())==n){
        cout<<"Yes";
    }
    else cout<<"No";
    
}