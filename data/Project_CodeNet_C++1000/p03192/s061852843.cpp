#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() {
    string N; cin >> N;
    int res = 0;
    for (auto n : N){
        if (n=='2') res++;
    }
    cout << res << endl;
}
