#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define nl cout<<"\n"
#define dbg(x) cout<<x<<" ";
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define UM unordered_map<int,int>
#define ULL unordered_map<ll,int>
void fun(){
    int n,m,x,y;    cin>>n>>m>>x>>y;
    int mn=INT_MAX,mx=INT_MIN;
    fi(0,n){
        int k;  cin>>k;
        mx=max(k,mx);
    }
    fi(0,n){
        int k;  cin>>k;
        mn=min(k,mn);
    }
    if(mn>x&&mn<=y&&mx<mn)
        cout<<"No War\n";
    else
        cout<<"War\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   fun();
}