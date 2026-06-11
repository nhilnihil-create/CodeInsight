#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int count = 0;
    int remaind, reverse = 0;
    for(int a = 1; a < 10; a++) {
        for(int b = 0; b < 10; b++) {
            for(int c = 0; c < 10; c++) {
                int num = 10001*a + 1010*b + 100*c;
                if(num >= A && num <= B) {
                    count++;
                }  
            }
        }
    }
    cout << count << endl;
}