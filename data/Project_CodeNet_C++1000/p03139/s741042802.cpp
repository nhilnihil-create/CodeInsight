#include <iostream>
using namespace std;
int main(void){
    int all, a, b;
    cin >> all >> a >> b;
    int max, min;
    max = a < b ? a : b;
    min = 0 > (all - a - b) * -1 ? 0 : (all - a - b) * -1;
    cout << max << " " << min << endl;
    return 0;
}
