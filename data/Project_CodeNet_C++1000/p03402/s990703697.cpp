#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b; cin>>a>>b;
    a--; b--;
    vector <vector<int>> g(100 ,vector <int>(100 ));
    int col = 0;//0白1黒
    for(int i=0;i<100;i++){
        if(i==100/2) col = 1;
        for(int j=0;j<100;j++){
            g[i][j] = col;
        }
    }
    /*cout<<a<<endl;
    cout<<b<<endl;*/
    for(int i=0;i<50;i+=2){
        for(int j=(i%2);j<100;j+=2){
            if(a&&j<100) {g[i][j]=1; a--;}
        }
    }
    int cnt = 0;
    for(int i=99;i>=50;i-=2){
        for(int j=1-(i%2);j<100;j+=2){
            if(b&&j<100) {g[i][j]=0; b--; cnt++;}
        }
    }
    //cout<<cnt<<endl;
    cout<<100<<' '<<100<<endl;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(g[i][j]) cout<<'.';
            else cout<<'#';
        }
        cout<<endl;
    }
}
