#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> p(N + 1);
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        p[num] = i;
    }
   
    int cnt = 1;
    int mx = 1;
    for (int num = 1; num < N; num++) {

        if (p[num] <= p[num + 1]) cnt++;
        else cnt = 1;
               
        mx = max(mx, cnt);
    }
    cout << N - mx << endl;
}
