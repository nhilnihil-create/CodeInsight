#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    double a, b;
    cin >> a >> b;
    
    cout << int((a + b)/2 + 0.5) << endl;
}
