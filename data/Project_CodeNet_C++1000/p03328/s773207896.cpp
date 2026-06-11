#include <bits/stdc++.h>
using namespace std;

/*
int main(){
    int a, b, c;
    cin >> a >> b;
    c = b - a + 1;
    for (int i = 0; i <= c; i++){
        a += i;
    }
    cout << a - b << endl;
}
*/

int main(){
    int a,b; cin >> a >> b;
    int num = b-a;
    int sum = 0;
    for(int i =0; i<b-a; ++i){
        sum += 1+i;
    }
    cout << sum-b <<  endl;
}