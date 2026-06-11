#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a.at(i).at(x-1) = true;
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
        int j = 0;
        while (a.at(j).at(i)) {
            j++;
            if (j == n)
                break;
        }
        if (j == n)
            count++;
    }
    cout << count << endl;
}