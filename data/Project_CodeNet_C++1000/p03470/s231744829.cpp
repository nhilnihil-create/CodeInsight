#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

    int N;
    cin >> N;
    map<int,int> n_map;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a ;

        n_map[a] = a;
    }

    cout << n_map.size() << endl;

    
}
