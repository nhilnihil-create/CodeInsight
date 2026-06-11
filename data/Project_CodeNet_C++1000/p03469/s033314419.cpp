#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    string a;
    cin >> a;
    for(int i = 0; i < a.size(); i++){
        if(i == 3){
            cout << '8';
        }
        else
        {
            cout << a[i];
        }
        
    }
    
    cout << endl;
}
