#include<bits/stdc++.h>
using namespace std;



int main(void){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int dist_x=x2-x1;
    int dist_y=y2-y1;
    cout<<x2-dist_y<<" "<<y2+dist_x<<" "<<x1-dist_y<<" "<<y1+dist_x<<endl;
    return 0;
}

