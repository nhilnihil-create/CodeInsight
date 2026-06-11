#include<iostream>
#include<vector>
using namespace std;

int main(){
    int c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cin>>c[i][j];
    }
    vector<int> x(3),y(3);
    x[0]=0;
    y[0]=c[0][0];
    for(int i=1;i<3;i++){
        x[i]=c[0][i]-y[0];
        y[i]=c[i][0];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x[j]+y[i]!=c[i][j]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}