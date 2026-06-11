#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    
    for(int i = 1; i <= 3; i++){
        if((a * b * i) & 1){
          cout << "Yes";
          return 0;
         }
    }
    
    cout <<"No";
    return 0;
}