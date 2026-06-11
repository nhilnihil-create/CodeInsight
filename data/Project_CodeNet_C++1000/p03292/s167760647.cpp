#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int zet(int a, int b){
    if(a>=b){
        return (a-b);
    }
    else{
        return (b-a);
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(zet(a,b), max(zet(b,c), zet(c,a))) << endl;
}
