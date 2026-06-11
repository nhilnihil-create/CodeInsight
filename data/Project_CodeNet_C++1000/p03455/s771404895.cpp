#include <bits/stdc++.h>
using namespace std;

int main(){

    int  a, b;

    scanf("%d %d", &a, &b);

    if((a * b) % 2 == 0){
        cout << "Even" << endl;
    }
    else{
        cout << "Odd" << endl;
    }
}