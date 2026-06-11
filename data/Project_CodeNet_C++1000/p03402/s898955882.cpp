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
#include <climits>
using namespace std;


int main(){
    long long a, b;
    cin >> a >> b;
    cout << 98 << ' ' << 99 << endl;
    a--, b--;
    for(int i = 0; i < 49; ++i){
        for(int j = 0; j < 99; ++j){
            if(!(i % 2) || !(j % 2) || !b){
                cout << '.';
            }
            else{
                cout << '#';
                b--;
            }
        }
        cout <<endl;
    }

    for(int i = 0; i < 49; ++i){
        for(int j = 0; j < 99; ++j){
            if(!(i % 2) || !(j % 2) || !a){
                cout << '#';
            }
            else{
                cout << '.';
                a--;
            }
        }
        cout <<endl;
    }
    
}
