#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

struct Edge{
    int u, v, w;
};

int main(){

    int L;
    cin >> L;

    vector<Edge> E;

    int digit = 0;
    int tempL = L;
    while(tempL != 0){
        digit++;
        tempL /= 2;
    }
    int len = digit - 1;

    int temp = (1 << (len - 1));
    for(int i = 0; i < len; i++){
        Edge e;
        e.u = i + 1;
        e.v = i + 2;
        e.w = temp;
        E.emplace_back(e);
        temp /= 2;
        e.w = 0;
        E.emplace_back(e);
    }

    int bit = (1 << (len - 1));
    tempL = L - ((1 << len));
    int sum = (1 << len);
    for(int i = len - 1; i >= 0 ; i--){
        if(bit & tempL){
            Edge e;
            e.u = 1;
            e.v = (len + 1 - i);
            e.w = sum;
            E.emplace_back(e);
            sum += (1 << i);
        }

        bit = (bit >> 1);
    }

    cout << len + 1 << " " << (int)E.size() << endl;
    for(auto e: E){
        cout << e.u << " " << e.v << " " << e.w << endl;
    }

    return 0;
}