#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int A,B,C,X,Y;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;
    cin >> Y;

    int max_number = max(X, Y)*2;
    int min_cost = C*max_number;
    int num_A, num_B;
    int cost;
    //int min_A=0, min_B=0, min_C=0;
    for(int num_C=0; num_C < max_number; num_C++){
        num_A = max(X - num_C / 2, 0);
        num_B = max(Y - num_C / 2, 0);
        cost = A * num_A + B * num_B + C * num_C;
        if(cost < min_cost) {
            min_cost = cost;
            /*min_A =  num_A;
            min_B =  num_B;
            min_C  = num_C;*/
        }
    }
    cout << min_cost << endl;
    //cout << min_A <<  min_B << min_C  << endl;
    return 0;
}