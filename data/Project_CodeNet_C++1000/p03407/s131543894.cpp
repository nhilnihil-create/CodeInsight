#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;

    int x = A+B;
     
    if(x - C >= 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

