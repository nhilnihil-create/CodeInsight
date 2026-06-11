#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define INVALID -1
#define mod 1e9+7
#define rep(n) for(int i=0;i<n;++i)
using namespace std;
int main(void){
    // Your code here!

int n,m;
vector<pair<ll, ll>> vec;
cin>>n>>m;
for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    vec.push_back({a,b});
}

sort(vec.begin(),vec.end(),[](auto val1, auto val2){
    
    return val1.second < val2.second;
});

ll ans=0;
ll l=vec[0].first,r=vec[0].second;
for(int i=1;i<m;i++){
    l= max(vec[i].first, l);
    r= min(vec[i].second,r);
}
cout<<max(ans, (r-l+1));
}
