#include<bits/stdc++.h>
using namespace std;

bool mx(int a,int b){
    if(a>b) return 1;
    else 0;
}
int main(){
    string a,b;
    int sx,sy;
    cin>>a>>b;
    sx = a.size();
    sy = b.size();
    int chk[sx+1][sy+1]={0};
    string ans="";
    int as=0;
    for(int i=0;i<=sx;i++) chk[i][0]=0;
    for(int j=0;j<=sy;j++) chk[0][j]=0;
    for(int i=1;i<sx+1;i++){
        for(int j=1;j<sy+1;j++){
            if(a[i-1]==b[j-1]){ 
                chk[i][j]=chk[i-1][j-1]+1;
            }
            else{
                chk[i][j]=max(chk[i-1][j],chk[i][j-1]);
            }
        }
    }
    ans="";
    int i=sx;
    int j=sy;
    while(i>0 && j>0){
        if(chk[i][j]==chk[i-1][j]){
            i--;
        }
        else if(chk[i][j]==chk[i][j-1]){
            j--;
        }
        else{
            ans = a[i-1]+ans;
            i--;
            j--;
        }
    }
    cout<<ans<<endl;
}