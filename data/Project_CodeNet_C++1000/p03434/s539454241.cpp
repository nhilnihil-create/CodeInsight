#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int N;

    cin >> N;

    int a[N];

    int a_sum = 0;
    int b_sum = 0;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }

    sort(a, a + N); 
    reverse(a, a + N); 

    for (int i = 0; i < N; i++) {

        //cout << a[i] << endl;

        if (i % 2 == 0){
            a_sum = a_sum + a[i];
        }
        else {
            b_sum = b_sum + a[i];
        }

    }
    cout << a_sum - b_sum << endl;

    return 0;
}