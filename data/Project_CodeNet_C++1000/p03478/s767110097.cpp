#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    for(int i = 1; i <= N; i++){
        int t = i;
        int sum = 0;
        while(t > 0){
            sum += t % 10;
            t /= 10;
        }
        if(A <= sum && sum <= B) ans += i;
    }
    cout << ans << endl;
}