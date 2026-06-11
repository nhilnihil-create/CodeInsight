#include <iostream>
using namespace std;
char dp[100][100];
int a,b;
void paint(int x,int y){
    dp[x][y]='#';
    dp[x+1][y]='#';
    dp[x+1][y-1]='#';
    return ;
}
int main(void){
    cout<<100<<" "<<100<<endl;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]='.';
        }
    }
    cin>>a>>b;
    b=b-1+(a==1);
    a--;
    int i;
    for(i=0;i<a/50;i++){
        for(int j=0;j<50;j++){
            paint(2*j,2*i+1);
        }
    }
    for(int j=0;j<a%50;j++){
        paint(2*j,2*i+1);
    }
    for(i=0;i<b/49;i++){
        for(int j=0;j<49;j++){
            dp[2*j+1][98-i*2]='#';
        }
    }
    for(int j=0;j<b%49;j++){
        dp[2*j+1][98-i*2]='#';
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }
}
