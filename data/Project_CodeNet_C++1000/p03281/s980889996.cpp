#include <iostream>
using namespace std;

int main() {

    int N;

    cin >> N;

    int total = 0;

    for (int i = 1; i <= N; i++) {

        if(i % 2 == 0){
            continue;
        }

        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if(i % j == 0){
                cnt++;
            }
        }
        if (cnt == 8){
            total++;
        }
    }
    cout << total << endl;

    return 0;

}