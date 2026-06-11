#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
const int MOD=1000000007;

const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a*n<b)cout<<a*n<<endl;
    else cout<<b<<endl;
    return 0;
}