#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
using namespace std;
int main(){
    int t;
    cin >> t;
    set<int> s;
    s.insert(t);
    int temp = t;
    int now = 1;
    while(1){
        if(temp % 2 == 0) temp /= 2;
        else temp = temp * 3 + 1;
        if(s.count(temp)) break;
        s.insert(temp);
        now++;
    }
    cout << now + 1 << endl;
}