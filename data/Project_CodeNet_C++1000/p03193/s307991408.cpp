#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define piii pair<int,pii>
#define pb push_back
#define mxn 200005

int main(){
sp;
int n,h,w,ans=0,x,y;
cin>>n>>h>>w;
while(n--){
    cin>>x>>y;
    if(x>=h&&y>=w)++ans;
}
cout<<ans;

return 0;}
