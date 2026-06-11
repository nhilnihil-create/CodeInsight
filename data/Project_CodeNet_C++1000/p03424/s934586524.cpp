#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int k;
    k = 0;
    int p, w, g, y;
    p = 0;
    w = 0;
    g = 0;
    y = 0;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        if(S == "P"){
            if(p == 0){
                p = 1;
                k++;
            }
        }else if(S == "W"){
            if(w == 0){
                w = 1;
                k++;
            }
        }else if(S == "G"){
            if(g == 0){
                g = 1;
                k++;
            }
        }else if(S == "Y"){
            if(y == 0){
                y = 1;
                k++;
            }
        }
    }
    if(k == 3){
        cout << "Three" << endl;
    }else if(k == 4){
        cout << "Four" << endl;
    }
}