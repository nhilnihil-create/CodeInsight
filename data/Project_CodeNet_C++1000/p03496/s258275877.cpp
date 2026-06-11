#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    auto mx = max_element(a.begin(), a.end()), mn = min_element(a.begin(), a.end());

    if(*mx < 0){
        cout << n - 1 <<endl;
        for(int i = 0; i < n - 1; ++i){
            cout << n - i << " " << n - i - 1 << endl;
        }
    }
    else if(*mn > 0){
        cout << n - 1 << endl;
        for(int i = 0; i < n - 1; ++i){
            cout << i + 1 << ' ' << i + 2 << endl;
        }
    }
    else if(abs(*mn) > abs(*mx)){
        cout << 2 * n - 1 << endl;
        for(int i = 0; i < n; ++i){
            cout << mn - a.begin() + 1 << ' ' << i + 1 << endl;
        }
        for(int i = 0; i < n - 1; ++i){
            cout << n - i << " " << n - i - 1 << endl;
        }
    }
    else{
        cout << 2 * n - 1 << endl;
        for(int i = 0; i < n; ++i){
            cout << mx - a.begin() + 1 << ' ' << i + 1 << endl;
        }
        for(int i = 0; i < n - 1; ++i){
            cout << i + 1 << " " << i + 2 << endl;
        }
    }
}
