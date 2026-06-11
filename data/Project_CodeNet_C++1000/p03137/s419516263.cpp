#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    int ans=0,n,m;
    vi x;
    priority_queue<int> d;
    cin>>n>>m;
    rep(i,m){
        int xi;
        cin>>xi;
        x.push_back(xi);
    }
    sort(x.begin(),x.end());
    if(n>=m){
        ans=0;
    }
    else{
        rep(i,m-1){
            d.push(x.at(i+1)-x.at(i));
        }
        rep(i,n-1){
            d.pop();
        }
        int z=d.size();
        rep(i,z){
            ans+=d.top();
            d.pop();
        }
    }
    cout<<ans;
}