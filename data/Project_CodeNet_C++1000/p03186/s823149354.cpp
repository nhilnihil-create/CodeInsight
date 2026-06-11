#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long
#define double long double

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    //poison -> antidote -> poison...
    int tot_antidote = a + b;
    if (a + b >= c - 1) {
        //eat everything
        cout << b + c;
        return 0;
    }
    int antidote_eaten = 0;
    int poison_eaten = 0;
    bool last_was_poison = false;
    while (tot_antidote > 0) {
        if (!last_was_poison) {
            c--;
            poison_eaten++;
            last_was_poison = true;
        } else {
            tot_antidote--;
            antidote_eaten++;
            last_was_poison = false;
        }
    }
    cout << min(antidote_eaten, b) + poison_eaten + 1;
}