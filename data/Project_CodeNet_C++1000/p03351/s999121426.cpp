#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
typedef pair<int,int> P;
#define mod 1000000007

int main(){
    int a,b,c,d;
    bool flag=false;
    cin>>a>>b>>c>>d;
    if(abs(c-a)<=d) flag=true;
    if(abs(b-a)<=d&&abs(c-b)<=d) flag=true;
    if(flag) cout <<"Yes" <<endl;
    else cout <<"No" <<endl;
    return 0;
}