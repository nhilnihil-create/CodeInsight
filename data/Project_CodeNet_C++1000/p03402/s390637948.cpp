#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout << 100 << " " << 100 << endl;
    char c[101][101];
    for(int i=0;i<50;i++)for(int j=0;j<100;j++)c[i][j]='.';
    for(int i=50;i<100;i++)for(int j=0;j<100;j++)c[i][j]='#';
    int i=0; int j=0;
    int k=0; int l=0;
    while(i<b-1){
        c[k][l]='#';
        i++;
        l+=2;
        if(l>=100){
            l=0;
            k+=2;
        }
    }
    k=51; l=0;
    while(j<a-1){
        c[k][l]='.';
        j++;
        l+=2;
        if(l>=100){
            l=0;
            k+=2;
        }
    }
    for(i=0;i<100;i++){
        for(j=0;j<100;j++)cout << c[i][j];
        cout << endl;
    }
}