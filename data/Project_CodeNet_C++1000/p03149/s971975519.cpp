#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <cctype>
#include <random>

using namespace std;

int main() {
    int n[4]={0,0,0,0};
    int l, sw=0;
    for (int i=0; i<4; i++) {
        cin >> l;
        if (l == 1) n[0]++;
        else if (l == 7) n[1]++;
        else if (l == 9) n[2]++;
        else if (l == 4) n[3]++;
    }
    for (int i=0; i<4; i++) {
        if (n[i] == 1) sw++;
    }

    if (sw == 4) cout << "YES" << endl;
    else cout << "NO" << endl;



    return 0;
}
