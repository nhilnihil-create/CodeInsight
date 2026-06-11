#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm> 
#include <math.h>
#include <queue>
#include <functional>
#include <map>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
    string s;
    cin >> s;

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'a') a++;
        else if (s[i] == 'b') b++;
        else c++;
    }

    if (max(a - b, b - a) <= 1 && max(b - c, c - b) <= 1 && max(c - a, a - c) <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;

}