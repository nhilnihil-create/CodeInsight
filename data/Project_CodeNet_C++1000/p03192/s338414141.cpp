#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;

    int a, b, c, d;
    a = N / 1000;
    b = (N - a * 1000) / 100;
    c = (N - a * 1000 - b * 100) / 10;
    d = (N - a * 1000 - b * 100) % 10;

    int count = 0;
    if (a == 2){
        count++;
    }
    if (b == 2){
        count++;
    }
    if (c == 2){
        count++;
    } 
    if (d == 2){
        count++;
    }

    cout << count << endl;
}