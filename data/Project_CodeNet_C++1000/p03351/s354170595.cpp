#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int>a(3);
    int d;
    for(int i=0; i<3; i++) cin >> a[i];
    cin >> d;

    if(abs(a[2]-a[0])<=d){
        cout << "Yes" << endl;
    } else if (abs(a[1]-a[0])<=d && abs(a[2]-a[1])<=d) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}