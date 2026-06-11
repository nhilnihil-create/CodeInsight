#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    long long c[5][5];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>c[i][j];
        }
    }
    for(int i=0;i<3;i++){
        int a=c[i][0];
        for(int j=0;j<3;j++){
            c[i][j]-=a;
        }
    }
    for(int i=0;i<3;i++){
        int a=c[0][i];
        for(int j=0;j<3;j++){
            c[j][i]-=a;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(c[i][j]!=0){
                cout<<"No"<<endl;
                return(0);
            }
        }
    }
    cout<<"Yes"<<endl;
    return(0);
}