#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<char> c(9);
    for (int i=0; i<9; i++) cin >> c.at(i);
    cout<<c[0]<<c[4]<<c[8]<<endl;
    return 0;
}
