

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;



bool aoki_win(char u, char d, int s,int h, string &taka, string &aoki){
    int max_y=h-1,min_y=0;
    //cout << min_y << " " << max_y << endl;
    for(int i=taka.size()-1;i>=0;i--){
        if(aoki[i]==u && max_y!=h-1){
            max_y++;
        }else if(aoki[i]==d && min_y!=0){
            min_y--;
        }
        //cout << min_y << " " << max_y << endl;
        if(taka[i]==u){
            min_y++;
        }else if(taka[i]==d){
            max_y--;
        }
        //cout << min_y << " " << max_y << endl;
        if(max_y<min_y){
            return false;
        }
    }
    return min_y<=s && s<=max_y;
}



int main(void){
    int H,W,N;
    int sr,sc;
    string S,T;
    cin >> H >> W >> N;
    cin >> sr >> sc;
    cin >> S;
    cin >> T;
    cout << (aoki_win('U','D',sr-1,H,S,T) && aoki_win('L','R',sc-1,W,S,T) ? "YES" : "NO") << endl;
    return 0;
}

