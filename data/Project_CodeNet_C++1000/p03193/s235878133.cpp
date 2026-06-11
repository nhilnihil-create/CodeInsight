#include <iostream>
using namespace std;

int main()
{
    int N, H, W;
    cin >> N >> H >> W;
    int count = 0;
    for(int n = 0; n < N; n++) {
        int A, B;
        cin >> A >> B;
        if(A >= H && B >= W) {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}