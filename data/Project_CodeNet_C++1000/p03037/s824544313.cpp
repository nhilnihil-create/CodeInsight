#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int n,m;
    cin>>n>>m;
    int x,y;
    x=-1e6,y=1e6;
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        x=max(p,x);
        y=min(y,q);
    }
    if(y-x+1>=0)
    cout<<y-x+1;
    else cout<<0;
}

