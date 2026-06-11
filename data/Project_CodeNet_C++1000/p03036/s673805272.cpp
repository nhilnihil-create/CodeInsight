#include <iostream>
using namespace std;

int main() {
    int r , D , X; 
    cin >> r >> D >> X; // 2 ≤ r ≤ 5 , 1 ≤ D ≤ 100 , D < X ≤ 200  
    for(int a = 1 ; a <= 10 ; a++){
        int x = r*X - D;
        cout << x << endl;
        X = x;
    }
	return 0;
}