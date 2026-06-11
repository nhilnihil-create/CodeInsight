#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int N,M,X,Y;

    cin >> N >> M >> X >> Y;

    int xm = -100;
    int ym = 100;

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;

        xm = max(x,xm);
    }

    for(int i = 0; i < M; i++){
        int y;
        cin >> y;

        ym = min(y,ym);
    }

    int Z = min(Y, ym);

    if(xm + 1 > Z || X + 1 > Z){
        cout << "War" << endl;

        return 0;
    }

    cout << "No War" << endl;
    

    return 0;
}