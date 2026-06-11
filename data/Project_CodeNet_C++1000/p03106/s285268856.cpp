#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> c;
    
    int count = 0;
    
    for(int i = 1; i <= min(a,b); i++) {
        if(a % i == 0 && b % i == 0) {
            c.push_back(i);
            count++;
        }
    }
    
    
     cout << c[count - k] << endl;

     return 0;
}
