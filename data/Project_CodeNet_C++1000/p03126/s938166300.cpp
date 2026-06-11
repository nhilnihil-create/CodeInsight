#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector <int> count(m);

    int k;
    int tmp;
    int id = 0;

    while(cin >> k) {
        for(int i = 0; i < k; i++) {
            cin >> tmp;

            count[tmp-1] ++;
        }

        id ++;
        if(id >= n) {
            break;
        }
    }

    int cnt = 0;

    for(int i = 0; i < m; i++) {
        if(count[i] == n) {
            cnt ++;
        }
    }

    cout << cnt << endl;

}