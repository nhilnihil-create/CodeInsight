#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;   cin >> h >> w;
    vector<vector<int> > a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    }
    vector<int> x, y, u, v;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w-1; j++) {
            if (a[i][j] % 2 == 0)
                continue;
            
            x.push_back(i);
            y.push_back(j);
            u.push_back(i);
            v.push_back(j+1);
            a[i][j]--;
            a[i][j+1]++;
        }
    }
    for (int j = 0; j < h-1; j++) {
        if (a[j][w-1] % 2 == 0)
            continue;

        x.push_back(j);
        y.push_back(w-1);
        u.push_back(j+1);
        v.push_back(w-1);
        a[j][w-1]--;
        a[j+1][w-1]++;
    }
    cout << x.size() << endl;
    for (int i = 0; i < x.size(); i++) 
        cout << x[i]+1 << " " << y[i]+1 << " " << u[i]+1 << " " << v[i]+1 << endl;
    return 0;
}