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
    int cnt=0;
    for(int i=1;i<=n;i+=2){
        int num=i,it=0;
        for(int j=1;j<=num;++j){
            if(num%j==0)it++;
        }
        if(it==8){
            cnt++;
        }
    }
    cout<<cnt;


}