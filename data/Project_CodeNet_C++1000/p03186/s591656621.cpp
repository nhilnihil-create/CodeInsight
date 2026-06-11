#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    ll a,b,c;cin>>a>>b>>c;
    if(c<=b) cout<<b+c<<endl;
    else cout<<b*2+min(c-b,a+1)<<endl;
    return 0;
}