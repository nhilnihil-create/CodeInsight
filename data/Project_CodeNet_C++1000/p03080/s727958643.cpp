#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

int main() {
   
    int n;
    string s;
    cin >> n >> s;
    int red = 0;
    int blue = 0;
    for (ll i=0;i<n;i++){
        if(s[i] == 'B'){
            blue++;
        }else{
            red++;
        }
    }
    if(red > blue){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}