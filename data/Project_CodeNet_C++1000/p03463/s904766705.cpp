#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    int k = b - a;

    if(k % 2 == 0){
        cout << "Alice" << endl;
    }else{
        cout << "Borys" << endl;
    }
}