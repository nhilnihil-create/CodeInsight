#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph=vector<vector<int>>;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int d[10][10];

void warshall_floyd(int n){
    for(int k=0;k<n;k++){ 
        for(int i=0;i<n;i++){ 
            for(int j=0;j<n;j++){ 
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    int h,w;cin>>h>>w;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int c;cin>>c;
            d[i][j]=c;
        }
    }
    warshall_floyd(10);
    ll ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int a;cin>>a;
            if(a==-1) continue;
            ans+=d[a][1];
        }
    }
    cout<<ans<<endl;
}