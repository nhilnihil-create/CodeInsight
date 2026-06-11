#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    string s;
    cin >> s;
    bool z = false;
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < s.length(); j++){
            string t = s;
            t.erase(i, j);
            if(t == "keyence"){
                z = true;
                break;
            }
        }
    }
    if(z) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}