#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W;
    int i,j;
    int h,w;

    cin >> H>>W ;
    char S[H][W];
    int count;
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            cin >> S[i][j];
        }
    }
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            if(S[i][j]=='.'){
                //cout << "at"<< i<<j <<endl;
                count=0;
                for(h=i-1;h<=i+1;h++){
                    for(w=j-1;w<=j+1;w++){
                        if(-1<h && h<H && -1<w && w<W){
                            if(S[h][w]=='#'){
                                //cout << "found #" << h << w << endl;
                                count++;
                            }
                        }
                    }
                }
                S[i][j]=count+'0';
                //cout<< S[i][j]<<endl;
            }
        }
    }
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            cout<< S[i][j] << flush;
        }
        cout<<endl;

    }
}