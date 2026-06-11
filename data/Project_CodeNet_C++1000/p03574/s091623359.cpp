#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    int H,W;cin>>H>>W;
    char S[H][W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>S[i][j];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='.'){
                int count=0;
                for(int k=max(0,i-1);k<=min(H-1,i+1);k++){
                    for(int l=max(0,j-1);l<=min(W-1,j+1);l++){
                        if(S[k][l]=='#'){
                            count++;
                        }
                    }
                }
                S[i][j]=count+'0';
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<S[i][j];
        }
        cout<<endl;
    }
    return 0;
}
