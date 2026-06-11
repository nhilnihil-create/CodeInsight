
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    int N;
    int A, B;
    cin >> N >> A >> B;

    // translate
    u_int64_t ans = 0;
    for(int i = 1; i <= N; i++) {
        int num = 0;
        num += i % 10;  // 1の位 
        num += (i / 10) % 10; // 10の位
        num += (i /100) % 10; // 100の位
        num += (i /1000) % 10; // 1000の位
        num += (i /10000) % 10; // 10000の位
        if (A <= num && num <= B) {
            ans += i;
        }
    }


    // output
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
