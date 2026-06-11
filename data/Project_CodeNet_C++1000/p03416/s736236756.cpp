#include<iostream>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    int i;
    int a, b, c, d, r;
    r = 0;
    for(i = A; i < B+1; i++){
        a = i / 10000;
        b = (i - a * 10000) / 1000;
        c = i % 10;
        d = (i - c) % 100 / 10;
        if(a == c && b == d){
            r++;
        }
    }
    cout << r << endl;
}