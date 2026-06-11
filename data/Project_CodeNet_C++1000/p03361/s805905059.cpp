#include <iostream>
#define ll long long int
#define N 55
using namespace std;
char s[N][N];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int a,b; 
bool search(int x,int y){
    for(int i=0;i<4;i++){
         int xx = x+dir[i][0];
         int yy = y+dir[i][1];
         if(xx>=0&&xx<a&&y>=0&&y<b){
             if(s[xx][yy]=='#')
                 return true;
        }
     }
     return false;
 }
 int main(){
     cin>>a>>b;
     for(int i=0;i<a;i++)
         for(int j=0;j<b;j++)
             cin>>s[i][j];
    for(int i=0;i<a;i++){
         for(int j=0;j<b;j++){
            if(s[i][j]=='#'){
                 bool prime = search(i,j);
                 if(!prime){
                     return 0*printf("No\n");
                 }
            }
         }
    }
     printf("Yes\n");
     return 0;
 }