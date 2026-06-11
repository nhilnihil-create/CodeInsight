#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<min(a,b)<<" "<<max(0,a+b-n)<<endl;
}
