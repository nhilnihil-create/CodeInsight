
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    int a, b;
    cin >> a >> b;


    // translate


    // output
    if((a * b) % 2 == 0) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
