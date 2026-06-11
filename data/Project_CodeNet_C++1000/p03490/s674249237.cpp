#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

const int MAX = 16001;

int main()
{
    string s;
    int x, y;
    cin >> s >> x >> y;
    int n = s.size();

    bitset<MAX> posX, posY;
    int i = 0;
    while(i < n && s[i] == 'F')
        ++ i;
    posX[n+i] = true;
    posY[n] = true;

    bool isDirX = true;
    while(i < n){
        if(s[i] == 'F'){
            int len = 0;
            while(i < n && s[i] == 'F'){
                ++ len;
                ++ i;
            }
            if(isDirX)
                posX = (posX << len) | (posX >> len);
            else
                posY = (posY << len) | (posY >> len);
        }
        else{
            isDirX = !isDirX;
            ++ i;
        }
    }

    if(posX[n+x] && posY[n+y])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
