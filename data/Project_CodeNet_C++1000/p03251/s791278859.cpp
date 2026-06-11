#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    int x=-101,y=101;
    int curr;
    for(int i = 0; i < N; ++i) {
        cin >> curr;
        if(curr > x) x = curr;
    }
    for(int i = 0; i < M; ++i) {
        cin >> curr;
        y = curr < y ? curr : y;
    }
    //cout << x << " " << y << endl;
    if( X < Y && x < y) {
        if(X > x) {
            if(Y <= y) {
                cout << "No War";
            }
            else{
                if(X < y) {
                    cout << "No War";
                }
                else{cout << "War";}
            }
        }
        else{
            if(Y >= y) {
                cout << "No War";
            }
            else{
                if(x < Y) 
                    cout << "No War";
                else {cout << "War";}
            }
        }
    }
    else{cout << "War";}
}
