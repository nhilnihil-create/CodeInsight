#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
int main(){
    int n, h, w;
    cin >> n >> h >> w;
    vector<vector<int>> a(1100, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> a.at(i).at(0) >> a.at(i).at(1);

    int count = 0;
    for(int i = 0; i < n; i++){
        if(a.at(i).at(0) >= h && a.at(i).at(1) >= w) count++;
    }

    cout << count << endl;
}
