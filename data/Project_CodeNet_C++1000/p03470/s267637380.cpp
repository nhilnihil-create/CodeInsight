#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {

    int N;

    cin >> N;

    int a[N];

    map<int,int> a_map;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }

    for (int i = 0; i < N; i++) {

        a_map[a[i]] = 1;
    }

    cout << a_map.size() << endl;

    return 0;
}