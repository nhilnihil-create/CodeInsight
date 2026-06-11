#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    int A,B;cin>>A>>B;
    vector<vector<char>> S(100,vector<char>(100,'.'));
    for(int i=50;i<100;i++){
        for(int j=0;j<100;j++){
            S[i][j]='#';
        }
    }
    A--;B--;
    for(int i=0;i<=(B-1)/50;i++){
        if(i!=(B-1)/50){
            for(int j=0;j<50;j++){
                S[2*i][2*j]='#';
            }
        }else{
            for(int j=0;j<(B-1)%50+1;j++){
                S[2*i][2*j]='#';
            }
        }
    }
    for(int i=0;i<=(A-1)/50;i++){
        if(i!=(A-1)/50){
            for(int j=0;j<50;j++){
                S[2*i+55][2*j]='.';
            }
        }else{
            for(int j=0;j<(A-1)%50+1;j++){
                S[2*i+55][2*j]='.';
            }
        }
    }
  cout<<100<<" "<<100<<endl;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cout<<S[i][j];
        }
        cout<<endl;
    }
    }
