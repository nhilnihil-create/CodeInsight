#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<string> mine(h+2);
    for (int i=1; i<=h; i++){
        string s; cin>>s;
        s = '.' + s + '.';
        mine[i]=s;
    }
    mine[0] = string(w, '.');
    mine[h+1] = string(w,'.');
    
    for (int i=1; i<=h; i++){
        for (int j=1; j<=w; j++){
            if(mine[i][j]=='#') cout << '#';
            else{
                int num = 0;
                for(int k=-1; k<=1; k++){
                    for(int l=-1; l<=1; l++){
                        if (k==0 && l==0) continue;
                        else num += mine[i+k][j+l]=='#';
                    }
                }
                cout << num;
            }
        }
        cout << endl;
    }
}