#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void){
    string s;
    cin >> s;
    
    int r[3];
    r[0] = r[1] = r[2] = 0;
    for (int i = 0; i < s.size(); i++) r[char(s[i]) - 'a']++;
    
    sort(r, r + 3);
    
    if (r[2] - r[0] <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
}