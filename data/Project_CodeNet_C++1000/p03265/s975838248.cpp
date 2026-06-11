#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(int argc, const char * argv[]) {
    
    vector<int> x(4, 0);
    vector<int> y(4, 0);
    
    for(int i=0; i<2; i++){
        cin >> x[i];
        cin >> y[i];
    }
    
    cout << x[1]-(y[1]-y[0]) << " ";
    cout << y[1]+(x[1]-x[0]) << " ";
    cout << x[0]-(y[1]-y[0]) << " ";
    cout << y[0]+(x[1]-x[0]) << endl;
    
    return 0;
}
