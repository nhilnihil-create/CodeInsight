#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int H,W;cin>>H>>W;
    vector<string>field(H);
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,1,0,-1};
    bool flag2=true;
    rep(i,H){
        cin>>field.at(i);
    }
    rep(i,H){
        rep(j,W){
            bool flag=true;
            if(field.at(i).at(j)=='#'){
                flag=false;
                rep(k,4){
                    int ny=i+dy[k]; int nx=j+dx[k];
                    if(ny>=H||ny<0||nx>=W||nx<0){
                        continue;
                    }
                    if(field.at(ny).at(nx)=='#'){
                        flag=true;
                    }
                }
            }
            if(flag==false){
                flag2=false;
            }
        }
    }
    if(flag2){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
