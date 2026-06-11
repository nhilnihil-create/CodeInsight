#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int n,k;
    cin>>n>>k;
    if(n%k==0) cout<<"0"<<endl;
    else cout<<"1"<<endl;
    return 0;
}