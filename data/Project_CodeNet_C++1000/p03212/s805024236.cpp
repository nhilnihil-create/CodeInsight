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
    set<int>st;
    int n;cin>>n;
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j){
            for(int k=1;k<=9;++k){
                if(i+j+k<=9){
                    string s1(i,'3');
                    string s2(j,'5');
                    string s3(k,'7');
                    s1+=s2;s1+=s3;
                    int val=stoi(s1);
                    if(val>int(1e9))continue;
                    do{
                        val=stoi(s1);
                        st.insert(val);
                    }
                    while(next_permutation(all(s1)));
                }
            }
        }
    }
    cout<<distance(st.begin(),st.upper_bound(n));
}