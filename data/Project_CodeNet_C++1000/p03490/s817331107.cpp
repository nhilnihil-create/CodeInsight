#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int main(void) {
    string s;
    int x, y;
    cin >> s >> x >> y;

    int start = 10'000;
    x += start;
    y += start;
    s.push_back('T');

    vector<int> v;
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'F') {
            cnt++;
        } else {
            v.push_back(cnt);
            cnt = 0;
        }
    }

    bool ok_x = false, ok_y = false;
    vector< bitset<20'000> > X(8000), Y(8000);
    X[0].set(start + v[0]);
    for(int i=1; i<8000; i++) {
        int index = 2*i;
        if(index >= v.size()) {
            if(X[i-1][x]) ok_x = true;
            break;
        }
        for(int j=0; j<20'000; j++) {
            if(X[i-1][j]) {
                X[i].set(j + v[index]);
                X[i].set(j - v[index]);
            }
        }
    }

    Y[0].set(start);
    for(int i=1; i<8000; i++) {
        int index = 2*i - 1;
        if(index >= v.size()) {
            if(Y[i-1][y]) ok_y = true;
            break;
        }
        for(int j=0; j<20'000; j++) {
            if(Y[i-1][j]) {
                Y[i].set(j + v[index]);
                Y[i].set(j - v[index]);
            }
        }
    }

    if(ok_x && ok_y) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
