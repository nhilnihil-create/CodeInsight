#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int H,W;
    cin>>H>>W;
    int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
    string fie[1000];
    int  fieans[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            fieans[i][j]=2100000000;
        }
    }
    for(int i=0;i<H;i++)cin>>fie[i];
    queue<int> Qx,Qy,Qte;
    Qx.push(0);
    Qy.push(0);
    Qte.push(0);
    while(Qx.size()!=0){
        int a,b,c;
        a=Qx.front();
        b=Qy.front();
        c=Qte.front();
        Qx.pop();
        Qy.pop();
        Qte.pop();
        //if(a<=0||b<=0||H<b||W<a){
            //continue;
        //}
        //printf("[%d][%d][%d]\n",a,b,c);
        for(int i=0;i<4;i++){
            if(a+dx[i]<0||b+dy[i]<0||H<=b+dy[i]||W<=a+dx[i]){
                continue;
            }
            if(fie[b+dy[i]][a+dx[i]]!='#'&&fieans[b+dy[i]][a+dx[i]]>c+1){
                fieans[b+dy[i]][a+dx[i]]=c+1;
                Qy.push(b+dy[i]);
                Qx.push(a+dx[i]);
                Qte.push(c+1);
            }
        }
    }
    int cou=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(fie[i][j]=='#')cou++;
            //printf("[%2d]",fieans[i+1][j+1]);
        }
        //puts("");
    }
    if(fieans[H-1][W-1]==2100000000){
        cout<<-1<<endl;
        return 0;
    }
    cout<<H*W-fieans[H-1][W-1]-1-cou<<endl;
    return 0;
}
