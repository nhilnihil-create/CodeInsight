#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a;
    cin >> a;
    cout << 48 - a << endl;
}
