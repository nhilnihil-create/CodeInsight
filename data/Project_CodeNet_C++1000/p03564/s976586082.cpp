#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int N, K;

    cin >> N >> K;

    int min = 10000000;

    // ４ビットの全組み合わせループ
    for (int tmp = 0; tmp < (1 << N); tmp++) {

        int D = 1;

        //ビット表現(0000)
        bitset<10> s(tmp);

        for (int i = 0; i < N; i++) {

            if (s.test(i)) {
                D = D * 2;
            }else{
                D = D + K;
            }
        }

        if (min > D){
            min = D;
        }
    }
    cout << min << endl;    

    return 0;

}



