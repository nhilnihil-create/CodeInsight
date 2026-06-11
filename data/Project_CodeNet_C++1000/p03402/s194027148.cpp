#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int A, B;

int main() {
    cin >> A >> B;
    vector< vector<char> > smap(110, vector<char>(110, '.'));
    for(int i = 0; i < 50; ++i) {
        for(int j = 0; j < 100; ++j) {
            smap.at(i).at(j) = '#';
        }
    }

    for(int i = 0; i < A-1; ++i) {
        int row = i/50;
        if(row % 2 == 0) {
            smap.at(2*row).at(2*(i%50)) = '.';
        }else {
            smap.at(2*row).at(2*(i%50)+1) = '.';
        }
    }

    cout << 100 << " " << 100 << endl;
    for(int i = 0; i < B-1; ++i) {
        int row = i/50;
        if(row % 2 == 0) {
            smap.at(51+2*row).at(2*(i%50)) = '#';
        }else {
            smap.at(51+2*row).at(2*(i%50)+1) = '#';
        }
    }

    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            cout << smap.at(i).at(j);
        }
        cout << endl;
    }
}