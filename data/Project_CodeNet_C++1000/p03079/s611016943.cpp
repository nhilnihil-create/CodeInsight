#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int A, B, C;

int main() {
    cin >> A >> B >> C;
    bool flag = A == B && B == C;
    cout << (flag? "Yes": "No") << endl;
}


