#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC110(void);
void ABC111(void);
void ABC112(void);
void ABC113(void);
void ABC114(void);
void ABC115(void);
void ABC116(void);
void ABC117(void);
void ABC118(void);
void ABC119(void);

int main(void){
    ABC110();
}

void ABC110(){
    int n,m,x,y,a,i;
    cin>>n>>m>>x>>y;
    vector<int> vecx,vecy;
    vecx.push_back(x);
    vecy.push_back(y);
    for(i=0;i<n;i++){
        cin>>a;
        vecx.push_back(a);
    }
    for(i=0;i<m;i++){
        cin>>a;
        vecy.push_back(a);
    }
    sort(vecx.begin(),vecx.end());
    sort(vecy.begin(),vecy.end());
    if(vecx[vecx.size()-1]<vecy[0])cout<<"No War"<<endl;
    else cout<<"War"<<endl;
}
