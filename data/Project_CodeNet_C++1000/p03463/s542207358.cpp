#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define ll long long

using namespace std;

int main(void){
    ll n, a, b;
    cin >> n >> a >> b;
    ll check = b-a-1;
    if(check%2==0)
        cout << "Borys" << endl;
    else
        cout << "Alice" << endl;
    return 0;
}
