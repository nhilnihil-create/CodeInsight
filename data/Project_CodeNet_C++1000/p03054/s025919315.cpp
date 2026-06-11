#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll H,W,N;
    cin >> H >> W >> N;
    ll sy,sx;
    cin >> sy >> sx;
    string S,T;
    cin >> S >> T;
    ll upperEdge = 1;
    ll bottomEdge = H;
    ll rightEdge = W;
    ll leftEdge = 1;

    for(int i = N - 1; i >= 0; i--){
        char tak = S[i];
        char ao = T[i];
        switch(ao){
            case 'L':
                rightEdge = min(rightEdge + 1,W);
                break;
            case 'R':
                leftEdge = max(leftEdge - 1,1ll);
                break;
            case 'D':
                upperEdge = max(upperEdge - 1,1ll);
                break;
            case 'U':
                bottomEdge = min(bottomEdge + 1,H);
                break;
        }
        switch(tak){
            case 'R':
                rightEdge = rightEdge - 1;
                break;
            case 'L':
                leftEdge = leftEdge + 1;
                break;
            case 'U':
                upperEdge = upperEdge + 1;
                break;
            case 'D':
                bottomEdge = bottomEdge - 1;
                break;
        }
        //cout << leftEdge << " " << rightEdge << " " << upperEdge << " " << bottomEdge << endl;
        if(leftEdge > rightEdge || upperEdge > bottomEdge){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(leftEdge <= sx && sx <= rightEdge && upperEdge <= sy && sy <= bottomEdge){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
