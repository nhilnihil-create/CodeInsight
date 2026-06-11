#include<iostream>
#include<cmath>
using namespace std;
struct point{
    int x;
    int y;
    int h;
};
int main(){
    int N;
    cin>>N;
    point *points=new point[N];
    for(int i=0;i<N;i++){
        cin>>points[i].x>>points[i].y>>points[i].h;
    }
    int H;
    int m,n;
    for(int i=0;i<=100;i++){
        int find=1;
        for(int j=0;j<=100;j++){
            find=1;
            for(int k=0;k<N;k++){
                if(!points[k].h)
                    continue;
                H=abs(i-points[k].x)+abs(j-points[k].y)+points[k].h;//找到第一个h非0点
            }
            for(int l=0;l<N;l++){
                if(points[l].h!=max(H-abs(i-points[l].x)-abs(j-points[l].y),0)){
                    find=0;
                    break;
                }
            }
            if(find){
                cout<<i<<" "<<j<<" "<<H;
                break;
            }
        }
        if(find)
            break;
    }
    return 0;
}