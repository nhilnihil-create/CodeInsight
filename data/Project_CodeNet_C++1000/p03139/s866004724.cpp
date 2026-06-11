#include<bits/stdc++.h>
typedef long long ll;
#define INF 100000000
#define MOD 100000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
    int n,a,b;
    cin>>n>>a>>b;
    int p=min(a,b),q;
    if((a+b)<n){
        q=0;
    }else{
        q=(a+b)-n;
    }
    cout<<p<<" "<<q<<endl;
    return 0;
}