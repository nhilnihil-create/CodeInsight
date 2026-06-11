#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define P pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
int n;
int a[200000],b[200000];
int tak=0,aok=0;
vector<P>vec;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>a[i]>>b[i];
        vec.push_back(make_pair(a[i]+b[i],a[i]));
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    rep(i,n){
        if(i%2==0){
            tak+=vec[i].second;
        }
        else{
            aok+=vec[i].first-vec[i].second;
        }
    }
    cout<<tak-aok<<endl;
    return 0;
}
