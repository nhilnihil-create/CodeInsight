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
    long long m, k, p = -1;
    cin >> m >> k;
    long long mm = 1 << m;
    if(k >= mm || (mm == 2 && k != 0)){
        cout << -1;
        return 0;
    }
    if(mm == 2 && k == 0){
        cout << "0 0 1 1";
        return 0;
    }
    vector<long long> a;
    for(int i = 0; i < mm; ++i){
        if(i != k){
            a.push_back(i);
        }
    }
    a.push_back(k);
    for(int j = mm - 1; j >= 0; --j){
        if(j != k){
            a.push_back(j);
        }
    }
    a.push_back(k);
    
    for(int i = 0; i < a.size(); ++i) cout << a[i] << " ";
}
