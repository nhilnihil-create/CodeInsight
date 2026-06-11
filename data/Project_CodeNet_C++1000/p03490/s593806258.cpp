#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
vector<int>x,y;
int dpx[8000][16005],dpy[8000][16005];
int main(void){
    char s[8005];
    cin>>s;
    int sl=strlen(s);
    int r=0;
    x.push_back(0);
    y.push_back(0);
    for(int i=0;i<sl;i++){
        if(s[i]=='F'){
            if(r==0)x.back()++;
            else y.back()++;
        }else{
            if(r==0)x.push_back(0);
            else y.push_back(0);
            
            r=(r+1)%2;
        }
    }
    int a,b;
    cin>>a>>b;
    dpx[0][x[0]+8000]=1;
    for(int i=1;i<x.size();i++){
        for(int j=0;j<=16001;j++){
            if(dpx[i-1][j]){
                if(j-x[i]>=0)dpx[i][j-x[i]]=1;
                if(j+x[i]<=16001)dpx[i][j+x[i]]=1;
            }
        }
    }
    dpy[0][8000]=1;
    for(int i=1;i<=y.size();i++){
        for(int j=0;j<=16001;j++){
            if(dpy[i-1][j]){
                if(j-y[i-1]>=0)dpy[i][j-y[i-1]]=1;
                if(j+y[i-1]<=16001)dpy[i][j+y[i-1]]=1;
            }
        }
    }
    if(dpx[x.size()-1][a+8000]&&dpy[y.size()][b+8000])cout<<"Yes\n";
    else cout<<"No\n";
}
