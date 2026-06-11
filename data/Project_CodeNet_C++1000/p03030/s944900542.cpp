#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    int N;
    cin >> N;
    
    vector<tuple<string, int, int>> sp(N);
    
    for (int i=0; i<N; i++) {
        int p;
        cin >> get<0>(sp.at(i)) >> p;
        get<1>(sp.at(i)) = 100-p;
        get<2>(sp.at(i)) = i+1 ;
    }
    
    
    stable_sort(sp.begin(), sp.end()) ;
    
    
    cout <<endl;
    for (tuple<string, int, int> t : sp) {
        string x;
        int y, z;
        tie(x, y, z) = t;
        cout << z << endl;
    }

}
