#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    char s[h+5][w+5];
    for(int i=1;i<=h;i++){
        s[i][0]='.';
        s[i][w+1]='.';
    }   
    for(int j=1;j<=w;j++){
        s[0][j]='.';
        s[h+1][j]='.';
    }
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)cin >> s[i][j];
    int flag=0;
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
        if(s[i][j]=='#'){
            if(s[i-1][j]=='.' && s[i+1][j]=='.' && s[i][j-1]=='.' && s[i][j+1]=='.')flag++;
        }
    }
    if(flag>0)cout << "No" << endl;
    else cout << "Yes" << endl;
}