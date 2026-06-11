#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,a,b;cin>>n>>a>>b;
    cout <<min(a,b)<<" "<<max(a+b-n,0)<<endl;
    
    return 0;
}