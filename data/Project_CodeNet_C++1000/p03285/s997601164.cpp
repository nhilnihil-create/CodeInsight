#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {

    int N;

    cin >> N;



    int a = N / 7;
    int b = (N / 4);

    if (N % 7 == 0 || N % 4 == 0 ){
        cout << "Yes" << endl;
        return 0;
    }


    // for (int i = 0; i <= b + 1; i++){
    //     int aa = 4 * i;
    //     int bb = 7 * (b - i);

    //     if (aa + bb == N){
    //         cout << "Yes" << endl;
    //         return 0;
    //     }
    // }
    int y4 = 1;
    int y7 = 1;

    int sum = 0;
 //do{
    do{
        sum = (y4 * 4) + (y7 * 7);

        if (sum == N){
            cout << "Yes" << endl;
            return 0;
        }
        if (sum > N){
            y4++;
            y7 = 1;
            continue;
        }
        
        y7++;


    } while (y4 <= b);
//} while (true);

    cout << "No" << endl;




}