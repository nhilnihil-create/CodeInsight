#include <iostream>
#include <algorithm>

using namespace std;

char tb[100][100];

void circle(int h, int w, char mk){
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            if(!(i==0 && j==0)) tb[h + i][w + j] = mk;
        }
    }
}

void dot(int h, int w, char mk){
    tb[h][w] = mk;
}

int main(){
    int A, B;
    cin >> A >> B;
    char mj, mn;
    if (A > B) {
        mj = '.';
        mn = '#';
    }
    else {
        mj = '#';
        mn = '.';
    }

    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) tb[i][j] = mn;
    }

    
    int h = 2, w = 2;
    for(int i=0; i<max(A, B); i++){
        if(i < min(A, B)-1) circle(h, w, mj);
        else dot(h, w, mj);
        w += 4;
        if(w > 95){
            w %= 96;
            h += 4;
        }
    }
    cout << 100 << " " << 100 << endl;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            cout << tb[i][j];
        }
        cout << endl;
    }
    return 0;
}