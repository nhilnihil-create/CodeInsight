#include<iostream>
#include<string>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    char c[h+2][w+2];
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++)cin>>c[i][j];
    }
    bool flag=true;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(c[i][j]=='.')continue;
            else{
                if(c[i][j-1]!='#'&&c[i][j+1]!='#'&&c[i-1][j]!='#'&&c[i+1][j]!='#')flag=false;
            }
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}