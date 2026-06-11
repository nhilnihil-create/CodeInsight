#include<iostream>

using namespace std;

int main(){
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int x=x2,y=y2;
    int dx,dy;
    dx=x2-x1;
    dy=y2-y1;

    for (int i=0;i<2;i++){
        swap(dy,dx);
        dx=-dx;
        x+=dx;
        y+=dy;
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}