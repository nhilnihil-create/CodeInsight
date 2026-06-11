#include <iostream>
#include <string>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    char S[60][60];
    int i,j,k,l;
    for(i=1; i<=H; i++){
        for(j=1; j<=W; j++){
            cin >> S[i][j];
        }
    }
    int count;

    for(i=1; i<=H; i++){
        for(j=1; j<=W; j++){
            if(S[i][j]=='.'){
                count=0;
                for(k=0; k<3; k++){
                    for(l=0; l<3; l++){
                        if(S[i-1+k][j-1+l]=='#') count++;
                    }
                }
                cout << count;
            }
            else cout << S[i][j];
        }
        cout << endl;
    }
        
        return 0;
}