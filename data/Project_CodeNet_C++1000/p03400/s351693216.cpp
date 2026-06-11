#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF (INT_MAX)
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(){
    int n,d,x;
    cin>>n>>d>>x;
    int ans=0;
    rep(i,n){
        int a;
        cin>>a;
        ans+=(d-1)/a;
    }
    cout<<ans+x+n<<endl;
}