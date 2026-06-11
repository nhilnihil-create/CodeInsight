#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int a[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    int hanbetu=0,a1,a2,a3,b1,b2,b3;
    for(i=0;i<=100;i++){
        a1=i;
        b1=a[0][0]-a1;
        b2=a[0][1]-a1;
        b3=a[0][2]-a1;
        for(j=0;j<=100;j++){
            a2=j;
            if(b1==a[1][0]-a2&&b2==a[1][1]-a2&&b3==a[1][2]-a2){
                for(k=0;k<=100;k++){
                    a3=k;
                    if(b1==a[2][0]-a3&&b2==a[2][1]-a3&&b3==a[2][2]-a3){
                        cout<<"Yes"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
}