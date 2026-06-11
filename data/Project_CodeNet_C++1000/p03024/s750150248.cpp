#include <iostream>

using namespace std;

int main(){
    string wins;
    getline(cin, wins);
    
    int toWin = wins.length()-7;
    
    for(int i=0;i<wins.length();i++){
        if(wins[i]=='o') toWin--;
    }
    
    cout << (toWin<=0 ? "YES" : "NO");
    
    return 0;
}
