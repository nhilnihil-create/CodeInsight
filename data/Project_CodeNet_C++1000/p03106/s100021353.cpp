#include <iostream>
#include <vector>

using namespace std;


int main(){
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> dev(0);
    
    for (int x = 1; x <= min(a,b); x++){
        if (a % x == 0 && b % x == 0)
            dev.push_back(x);
    }
    cout << dev.at(dev.size() - k) << endl;
}