#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <chrono>
#include <vector>

using namespace std;

int main () {
    int N;
    cin >> N;
    vector<long long int> x(N), y(N);
    for (int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
    }
    vector<string> s(N, "");
    vector<long long int> d;

    if ( ((x[0] + y[0]) & 1) != 1 ) {
        d.push_back(1);
        for (int i=0; i<N; i++) {
            y[i]--;
            s[i].push_back('U');
        }
    }

    long long int step = 1;
    while( step < (1LL << 33) ) {
        d.push_back(step);
        for(int i=0; i<N; i++) {
            if ( ((x[i] + y[i]) & 1) != 1 ) {
                cout << -1 << endl;
                return 0;
            }
            if ( x[i] & 1 ) {
                if (((x[i] - 1) & 2 ) == (y[i] & 2)) {
                    x[i]++;
                    s[i].push_back('L');
                } else {
                    x[i]--;
                    s[i].push_back('R');
                }
            } else {
                if (((y[i] - 1) & 2 ) == (x[i] & 2)) {
                    y[i]++;
                    s[i].push_back('D');
                } else {
                    y[i]--;
                    s[i].push_back('U');
                }
            }
            x[i] /= 2;
            y[i] /= 2;
        }
        step <<= 1;
    } 
    d.push_back(step);
    for (int i=0; i<N; i++) {
        if (x[i] == 1) {
            s[i].push_back('R');
        } else if (x[i] == -1) {
            s[i].push_back('L');
        } else if (y[i] == 1) {
            s[i].push_back('U');
        } else {
            s[i].push_back('D');
        }
    }
    int m = (int) d.size();
    cout << m << endl;
    for (int i=0; i<m; i++) {
        if (i>0) {
            cout << " ";
        }
        cout << d[i];
    }
    cout << endl;
    for (int i=0; i< N; i++) {
        cout << s[i] << endl;
    }
    return 0;
}