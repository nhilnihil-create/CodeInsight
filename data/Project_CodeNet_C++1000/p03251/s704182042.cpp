#include<iostream>
using namespace std;

int main(){
    int n,m,X,Y;cin>>n>>m>>X>>Y;
    int maxx=-101;
    int miny=101;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        maxx=max(maxx,x);
    }
    for(int i=0;i<m;i++){
        int y;cin>>y;
        miny=min(miny,y);
    }
    bool war=true;
    for(int z=X+1;z<=Y;z++){
        if(X<z&&z<=Y&&maxx<z&&z<=miny) war=false;
    }
    if(war) cout<<"War"<<endl;
    else cout<<"No War"<<endl;
}