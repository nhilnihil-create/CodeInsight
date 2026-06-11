#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (int)(n);i++)

int main() {
    int N,num=3;
    char color;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> color;
        if(color=='Y'){
            num = 4;
        }
    }
    if(num==3){
        cout << "Three" << endl;
    }else if(num==4){
        cout << "Four" << endl;
    }
}