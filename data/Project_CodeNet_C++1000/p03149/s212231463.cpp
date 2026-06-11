#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main(){

    map <int, int> m;
    for (int i = 0; i < 4; i++){
        int x;
        cin >> x;
        m[x] ++;
    }
    
    if (m[1] == 1 && m[9] == 1 && m[7] == 1 && m[4] == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    

    
    return 0;
}