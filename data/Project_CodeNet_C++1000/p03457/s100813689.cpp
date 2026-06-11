#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> t(N+1, 0), x(N+1, 0), y(N+1, 0);
    
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i < N+1; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    bool reachable = false;
    for(int i = 1; i < N+1; i++){
        int dist = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        int diff = t[i] - t[i-1] - dist;
        if(diff >= 0 && diff % 2 == 0){
            reachable = true;
        } else {
            reachable = false;
            break;
        }
    }

    if(reachable){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
