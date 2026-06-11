#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>x[i][j];
        }
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            bool b=true;
            int h;
            for(int k=0;k<n;k++){
                if(x[k][2]){
                    h=abs(x[k][0]-i)+abs(x[k][1]-j)+x[k][2];
                    break;
                }
            }
            for(int k=0;k<n;k++){
                 if(max(0,h-abs(x[k][0]-i)-abs(x[k][1]-j))!=x[k][2])b=false;
            }
            if(b){
                cout<<i<<" "<<j<<" "<<h<<endl;
                return 0;
            }
        }
    }
}