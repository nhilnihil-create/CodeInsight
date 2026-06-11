#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

void vector_dump(std::vector<vector<bool> > vec) {
    std::cout << "[ ";
    for (auto j:vec) {
        std::cout << "[ ";
        for (auto i:j) {
            std::cout << (int)i << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

void vector_dump(std::vector<int> vec) {
    std::cout << "[ ";
    for (int i:vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
	int x, y; 
	cin >> s >> x >> y;
    vector<vector<bool> > dpx(s.length(), vector<bool>(s.length(), false));
    vector<vector<bool> > dpy(s.length(), vector<bool>(s.length(), false));
    
    int X = 0, Y = 0;
    int cnt = 0;
    
    
    
    for (auto c:s) {
        if (c == 'T') cnt++;
    } 
    if (cnt % 2 == 0) {
        X = cnt / 2 + 1;
        Y = cnt / 2;
    } else {
        X = Y = cnt / 2 + 1; 
    }
    vector<int> xi(X);
    vector<int> yi(Y);

    cnt = 0;
    
    for (auto c:s) {
        if (c == 'T') {
            cnt++;
        } else {
            cnt % 2 == 0 ? xi[cnt / 2] += 1 : yi[cnt / 2] += 1;
        }
    }

    dpx[0][xi[0]] = true;
    for (int i = 0; i < X-1; i++) {
        for (int e = 0; e < dpx[i].size(); e++) {
            if (dpx[i][e]) {
                if (xi[0] < e - xi[i+1]) dpx[i+1][e-xi[i+1]] = true;
                dpx[i+1][e+xi[i+1]] = true;
            }
        }
    }
    
    dpy[0][0] = true;
    for (int i = 0; i < Y; i++) {

        for (int e = 0; e < dpy[i].size(); e++) {

            if (dpy[i][e]) { 

                if (0 <= e - yi[i]) dpy[i+1][e-yi[i]] = true;
                dpy[i+1][e+yi[i]] = true;
                
                
            }
        }
    }
    

    if (xi[0] > x) x = xi[0] + (xi[0] - x);
    if (0 > y) y = -y;
    if (dpx[X-1][x] && dpy[Y][y]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    
    return 0;
}