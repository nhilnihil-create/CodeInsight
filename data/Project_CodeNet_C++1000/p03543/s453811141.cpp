#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a,b,c,d;
    d=N%10;
    c=(N-d)%100/10;
    b=(N-d-c*10)%1000/100;
    a=(N-d-c*10-b*100)%10000/1000;

    if(((a==b)&&(b==c))||((b==c)&&(c==d))){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}