#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> a;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push(tmp);
    }

    int aSum = 0, bSum = 0;
    for(int i = 0; !a.empty(); i++) {
        if(i % 2 == 0) {
            aSum += a.top();
        } else {
            bSum += a.top();
        }
        a.pop();
    }
    
    cout << aSum - bSum << endl;
    
    return 0;
}