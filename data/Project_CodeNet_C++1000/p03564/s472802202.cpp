#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    int disp = 1;
    int add = 1;
    int multi = 1;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        multi *= 2;
        add += K;
        if(multi > add){
            disp = add;
        }else{
            disp = multi;
        }
        multi = disp;
        add = disp;
    }
    cout << disp << endl;
}