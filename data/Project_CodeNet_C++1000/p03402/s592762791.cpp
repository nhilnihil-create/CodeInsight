#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
char gri[100][100];
    
    rep(i,100)
        {rep(j,100){
            if(i<50){gri[i][j]='#';}
            else {gri[i][j]='.';}
        }
        }
    int flag=0;
    rep(i,48){
        rep(j,100){
            if(a==0){
                flag=1;
                break;
            }
            
            if((gri[i+1][j]=='#'&&i+1<50)&&(gri[i-1][j]=='#'&&i-1>0)&&(gri[i][j-1]=='#'&&j-1>0)&&(gri[i][j+1]=='#'&&j+1<100)){
                if((gri[i+1][j+1]=='#'&&(i+1<50)&&(j+1<100))&&(gri[i+1][j-1]=='#'&&(i+1<50)&&(j-1>0))&&(gri[i-1][j+1]=='#'&&(i-1>0)&&(j+1<100))&&(gri[i-1][j-1]=='#'&&(i-1>0)&&(j-1>0))){
                gri[i][j]='.';
                a--;
                }
            }
        }
               if(flag==1){
                   break;
               }
    }
        flag=0;
               for(int i=50;i<100;i++){
                   rep(j,100){
                       if(b==0){
                           flag=1;
                           break;
                       }
                       
                       if((gri[i+1][j]=='.'&&i+1<100)&&(gri[i-1][j]=='.'&&i-1>51)&&(gri[i][j-1]=='.'&&j-1>0)&&(gri[i][j+1]=='.'&&j+1<100)){
                           if((gri[i+1][j+1]=='.'&&(i+1<100)&&(j+1<100))&&(gri[i+1][j-1]=='.'&&(i+1<100)&&(j-1>0))&&(gri[i-1][j+1]=='.'&&(i-1>51)&&(j+1<100))&&(gri[i-1][j-1]=='.'&&(i-1>51)&&(j-1>0))){
                               gri[i][j]='#';
                           b--;
                           }
                       }
                          }
                          if(flag==1){
                              break;
                          }
                          }
    cout<<100<<" "<<100<<endl;
    rep(i,100)
    {rep(j,100){
        cout<<gri[i][j];
    }
        cout<<endl;
    }
return 0;
}
