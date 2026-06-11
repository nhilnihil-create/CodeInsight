#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N;

    cin >> N;

    //int l0 = 2;
    //int l1 = 1;

    vector<long> L;
    L.push_back(2);
    L.push_back(1);


    int ans = 0;

    for (int i = 0; i <= N; i++){
      L.push_back(L.at(L.size() -1) + L.at(L.size() -2));
    }

    cout << L.at(N) << endl;

    return 0;

}