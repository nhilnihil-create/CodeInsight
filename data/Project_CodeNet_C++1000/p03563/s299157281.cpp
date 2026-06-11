#include <bits/stdc++.h>
using namespace std;

int main(){
    int now_rate;
    int to_rate;
    int next_rate;

    cin >> now_rate >> to_rate;
    next_rate = 2 * to_rate - now_rate;
    cout << next_rate;
}