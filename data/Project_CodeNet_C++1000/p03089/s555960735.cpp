#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> b(N);
    for (int i=0;i<N;i++) {
        cin >> b[i];
        b[i]--;
    }
    vector<int> step;
    while (b.size() > 0){
        bool flag = false;
        for (int i=b.size()-1;i>=0;i--){
            if (i==b[i]) {
                step.push_back(i);
                b.erase(b.begin()+i);
                flag = true;
                break;
            }
        }
        if (!flag){
            cout << -1 << "\n";
            return 0;
        }
    }
    for (int i=step.size()-1;i>=0;i--){
        cout << step[i]+1 << "\n";
    }

    return 0;
}