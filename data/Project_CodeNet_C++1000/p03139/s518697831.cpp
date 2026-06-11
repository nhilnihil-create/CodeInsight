#include <iostream>
using namespace std;
int main(void){
    int N; cin >> N;
    int X, Y; cin >> X >> Y;
    cout << min(X, Y) << " " << max(0, X + Y - N) << endl;
}
