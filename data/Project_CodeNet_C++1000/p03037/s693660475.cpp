#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int l=0,r=n;
    for(int i=0;i<m;i++){
        int lc,rc;
        cin>>lc>>rc;
        if(lc>l)
            l=lc;
        if(rc<r)
            r=rc;
    }
    if(l<=r)
        cout<<r-l+1;
    else
        cout<<0;
    
}