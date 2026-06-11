#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin>>n>>k;
    vector<int> elem(n+1);
    for (int i = 0; i < n; i++) {
        cin>>elem[i];
    }
    bool canWin[k+1];
    canWin[0] = 0;
    for (int stones = 1; stones <= k; stones++) {
        canWin[stones] = 0;
        for (int index = 0; index < n; index++) {
            if (elem[index] <= stones && !canWin[stones - elem[index]]) {
                canWin[stones] = 1;
                break;
            }
        }
    }
    if (canWin[k])
        cout<<"First"<<"\n";
    else
        cout<<"Second"<<"\n";
    return 0;
}
