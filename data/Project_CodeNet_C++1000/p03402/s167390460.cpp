#include <bits/stdc++.h>
using namespace std;

int main(){

    int A, B;
    cin >> A >> B;

    vector<vector<char> > white(50, vector<char>(100, '.'));
    vector<vector<char> > black(50, vector<char>(100, '#'));
    A--; B--;

    for(int i = 1; i < 50 - 1; i += 2){
        if(A == 0) break;
        for(int j = 1; j < 100 - 1; j += 2){
            black[i][j] = '.';
            A--;
            if(A == 0) break;
        }
    }

    for(int i = 1; i < 50 - 1; i += 2){
        if(B == 0) break;
        for(int j = 1; j < 100 - 1; j += 2){
            white[i][j] = '#';
            B--;
            if(B == 0) break;
        }
    }

    cout << 100 << " " << 100 << endl;
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 100; j++){
            cout << white[i][j];
        }
        cout << endl;
    }
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 100; j++){
            cout << black[i][j];
        }
        cout << endl;
    }

    return 0;
}