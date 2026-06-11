#include<bits/stdc++.h>
using namespace std;

int N;
char s[400][400];
char c[400][400];

bool check(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(s[i][j]==s[j][i]) continue;
            else return false;
        }
    }
    return true;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> c[i][j];
        }
    }
    int ans=0;
    for(int d=0;d<N;d++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j+d<N){
                    s[i][j+d]=c[i][j];
                }else{
                    s[i][j+d-N]=c[i][j];
                }
            }
        }
        if(check()) ans++;
    }
    cout << ans*N << endl;
}