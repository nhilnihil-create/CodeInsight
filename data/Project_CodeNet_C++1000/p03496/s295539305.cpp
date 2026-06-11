#include <bits/stdc++.h>
using namespace std;
#define ll	    long long
#define vi      vector <ll>
#define vii     vector <pair<int,int>>
#define ii      pair<int,int>
#define loop(n)	for(ll i=0;i<n;i++)
#define pb      push_back
const ll mod=1e9+7;
void fast();
int main()
{
    int n;
    cin>>n;
    ll a[n];
    int mx=-1e9,mn=1e9,x=0,y=0;
    loop(n){
        cin>>a[i];
        if(a[i]>mx)
            mx=a[i],x=i+1;
        if(a[i]<mn)
            mn=a[i],y=i+1;
    }
    vii res;
    if(mx+mn>0){
        for(int i=0;i<n;i++){
            if(a[i]<=0)
                res.pb({x,i+1});
        }
        for(int i=1;i<n;i++)
            res.pb({i,i+1});
    }
    else{
        for(int i=0;i<n;i++)
            if(a[i]>=0)
                res.pb({y,i+1});
        for(int i=n-2;i>=0;--i)
            res.pb({i+2,i+1});
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
        cout<<res[i].first<<" "<<res[i].second<<endl;
}
void fast(){
std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
/// 20
/// 15 7 13 15 15 15 15 13 19
/*

*/
