#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,X,Y;
int x[105],y[105];
int main(void){
    cin>>n>>m>>X>>Y;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<m;i++){
        cin>>y[i];
    }
    sort(x,x+n); sort(y,y+m);
    if(x[n-1]<y[0]&&x[n-1]<Y&&X<y[0]){
        cout<<"No War"<<endl;
    }else{
        cout<<"War"<<endl;
    }

}

