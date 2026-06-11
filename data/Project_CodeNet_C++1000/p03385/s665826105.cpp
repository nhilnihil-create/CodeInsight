#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    string  a;
    cin >> a;
    set<char> s;
    for(int i = 0; i < 3; i++){
        s.insert(a[i]);
    }
    if(s.size() == 3){
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
    
    cout << endl;
}
