#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int h,w;
    cin>>h>>w;
    char c[h][w];
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin>>c[i][j];
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(c[i][j]=='#'){
                count2++;
                if(c[i][j-1]=='#'||c[i][j+1]=='#'||c[i-1][j]=='#'||c[i+1][j]=='#'){
                    count1++;
                }
            }
        }
    }
    cout<<((count1==count2)?"Yes":"No")<<endl;
}