#include<iostream>
using namespace std;

main(){
    int N;
    int x[110000];
    int y[110000];
    int t[110000];

    cin >> N;
    x[0] = 0;
    y[0] = 0;
    t[0] = 0;

    for (int i = 1; i <= N;i++) cin >> t[i] >> x[i] >> y[i];
    bool arrive = true;
    int dist = 0;
    int dt = 0;

    for (int j = 1; j <= N; j++){
        dt = t[j] - t[j-1];
        dist = abs(x[j] - x[j-1]) + abs(y[j] - y[j-1]);
        if (dist > dt) {
            arrive = false;
            break;
        }
        if (dist % 2 != dt % 2) {
            arrive = false;
            break;
        }
    }

    if (arrive) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 