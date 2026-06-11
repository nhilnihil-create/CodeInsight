#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int u = 0, v= 0;
    for(int i = 0; i < s.size(); i++){
        if(s.at(i) == '0') u++;
        else v++;
    }
    cout << 2*min(u,v) << endl;    
}