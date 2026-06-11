#include <iostream>
using namespace std;

int main() {
    string stra;
    int x,y,z;
    cin >> x >> y;
    cin >> stra;
    y=y-1;
    z = (int)stra[y];
    z=z+32;
    stra[y]= (char)z;
    for(int i=0;i<x;i++){
        cout << stra[i];
    }
    cout << endl;
}