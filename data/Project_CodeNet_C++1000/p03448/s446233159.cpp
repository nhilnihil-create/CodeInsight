#include <iostream>
using namespace std;

int main() {

    int A; // 500
    int B; // 100
    int C; // 50
    int X;

    int a500 = 500;
    int b100 = 100;
    int c50 = 50;

    int p = 0;
    
    cin >> A >> B >> C >> X;

    for (int i = 0; i <= A; i++) {
        int a_tmp = a500 * i;

        if (a_tmp == X){
            //cout <<  a_tmp << endl;
            p = p + 1; 
            continue;
        }

        for (int j = 0; j <= B; j++) {
            int b_tmp = b100 * j;

            if (a_tmp + b_tmp == X){
                //cout <<  a_tmp << " " << b_tmp << endl;
                p = p + 1; 
                continue;
            }

            for (int k = 0; k <= C; k++) {
                int c_tmp = c50 * k;

                if (a_tmp + b_tmp + c_tmp == X){
                    //cout <<  a_tmp << " " << b_tmp << " " << c_tmp << endl;
                    p = p + 1; 
                    continue;
                }
            }
        }
    }

    cout <<  p << endl;

    return 0;

}