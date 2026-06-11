#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>

#define DIV 1000000007
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int dis = B - A + 1;
    if (dis % 2)
        cout << "Alice" << endl;
    else
        cout << "Borys" << endl;
}
