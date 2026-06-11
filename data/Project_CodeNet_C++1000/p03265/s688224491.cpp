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
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    x2-=x1;y2-=y1;
    x4=-y2;y4=x2;
    x3=(x2+x4);
    y3=(y2+y4);
    cout<<x3+x1<<" "<<y3+y1<<" "<<x4+x1<<" "<<y4+y1;
    
}