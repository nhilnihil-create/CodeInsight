#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=m/n;i>=0;i--){
        int x=m-i*(n-1);
        if(x%i==0){
            cout<<i<<endl;
            return 0;
        } 
    }
} 
