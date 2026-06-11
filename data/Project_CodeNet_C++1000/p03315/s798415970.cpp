#include <iostream>
using namespace std;

int main() {
    string stra;
    int x=0,y;
    cin >> stra;
    for(int i=0;i<4;i++){
        char xy = stra[i];
        y = (int)xy;
        if(y==43){
            x=x+1;
        }else if (y==45){
            x=x-1;
        }
    }
    cout << x << endl;
}