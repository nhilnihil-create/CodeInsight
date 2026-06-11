#include<iostream>
using namespace std;

int main(void){
        int n, a, b;
        cin >> n >> a >> b;
        int max = a;
        if (max > b) max = b;
        int min = a + b - n;
        if (min < 0) min = 0;
        cout << max << " " << min << endl;
        return 0;
}