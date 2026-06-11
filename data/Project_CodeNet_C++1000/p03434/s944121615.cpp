#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    int AliceScore = 0;
    int BobScore = 0;
    cin >> n;


    vector<int> a(n);
    for (int i = 0; i < a.size(); i++) {
        cin >> a.at(i);
    }

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            AliceScore += a.at(i); 
        }
        else {
            BobScore += a.at(i);     
        }
    }

    cout << AliceScore - BobScore << endl;

}