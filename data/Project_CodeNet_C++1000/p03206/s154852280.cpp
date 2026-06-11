#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int a;
    cin >> a;
    if(a == 25){
        cout << "Christmas";
    }
    else if(a == 24){
        cout << "Christmas Eve";
    }
    else if(a == 23){
        cout << "Christmas Eve Eve";
    }
    else{
        cout << "Christmas Eve Eve Eve";
    }
    cout << endl;
}
