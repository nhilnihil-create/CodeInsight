#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;


int main()
{
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    
    vector<int> y(M);
    for (int i = 0; i < M; i++) {
        cin >> y[i];
    }
    sort(y.begin(), y.end());
    
    
    int maxX = X;
    int minY = Y;
    for (int i = 0; i < N; i++) {
        maxX = max(maxX, x[i]);
    }
    for (int i = 0; i < M; i++) {
        minY = min(minY, y[i]);
    }

    if (maxX < minY) {
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }
    
    return 0;
}