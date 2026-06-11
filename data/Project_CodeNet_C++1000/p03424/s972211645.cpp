#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin >> N;

    bool flagY = false;
    rep(i, N){
        string s;
        cin >> s;
        if(s == "G" || s == "W" || s == "P"){
        }
        else{
            flagY = true;
            break;
        }
    }

    if(flagY){
        cout << "Four" << endl;
    }
    else{
        cout << "Three" << endl;
    }
}