#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;
int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r=0, b=0;
    for (int i=0; i<n; i++){
        if(s[i]=='R') r++;
        else  b++;
    }

    cout << ((r>b) ? "Yes":"No") << endl;
    return 0;
}