#include<iostream>
using namespace std;

int main(){
    int n,m,X,Y;
    cin>>n>>m>>X>>Y;

    int maxx=X;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        maxx=max(maxx,x);
    }

    int miny=Y;
    for(int i=0;i<m;i++){
        int y;cin>>y;
        miny=min(miny,y);
    }

    if(maxx<miny) cout<<"No War"<<endl;
    else cout<<"War"<<endl;
}