#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

int f(int num){
    if(num % 2 == 0) return num/2;
    else return 3*num+1;
}
int main() {
    int s;
    vector<int> vec;
    int ans = 0;

    cin >> s;
    while(1) {
        if (find(vec.begin(), vec.end(), s) == vec.end()) {
            ans ++;
            vec.push_back(s);
            s = f(s);
        }else{
            break;
        }
    }
    cout << ans+1;
    return 0;
}