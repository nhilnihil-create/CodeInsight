#include <iostream>
using namespace std;

int main(){
    int N;
    int A, B;
    cin >> N >> A >> B;

    int ans = 0;

    for(int i = 1; i <= N; i++){
        int a[5];
        a[1] = i / 10000;
        a[2] = (i - 10000*a[1]) / 1000;
        a[3] = (i - 10000*a[1] - 1000*a[2]) / 100;
        a[4] = (i - 10000*a[1] - 1000*a[2] - 100*a[3]) /10;
        a[5] = (i - 10000*a[1] - 1000*a[2] - 100*a[3] - 10*a[4]);

        int sum = a[1] + a[2] + a[3] + a[4] + a[5];
        if((sum >= A) && (sum <= B)) ans += i;
    }

    cout << ans << endl;
}