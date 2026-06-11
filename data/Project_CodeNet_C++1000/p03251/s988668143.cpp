#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,X,Y,x,y;
    cin>>n>>m>>X>>Y;
    int max_X=X,min_Y=Y;
    for (int i=0;i<n;i++) {
        cin>>x;
        if (x>max_X) {
            max_X=x;
        }
    }
    for (int j=0;j<m;j++) {
        cin>>y;
        if (y<min_Y) {
            min_Y=y;
        }
    }
    if (max_X<min_Y&&min_Y-max_X>0) {
        cout<<"No War"<<endl;
    } else {
        cout<<"War"<<endl;
    }
}