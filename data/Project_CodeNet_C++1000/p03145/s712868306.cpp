#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int h = 0, w = 0;
    if(a > b){
        h = b;
        if(a > c){
            w = c;
        }else{
            w = a;
        }
    }else{
        h = a;
        if(b > c){
            w = c;
        }else{
            w = b;
        }
    }

    cout << (h * w)/2 << endl;
}