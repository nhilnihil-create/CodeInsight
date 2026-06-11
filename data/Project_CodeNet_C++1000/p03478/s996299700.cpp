#include<iostream> 
using namespace std;

int main(){
    int A, B,N;
    int sum,ans = 0;;
    int cur =10;

    cin >> N >> A >> B;

    for(int i = 1;i <= N;i++){
        sum = 0;
        cur = i;
        while(cur > 0){
            sum += cur%10;
            cur /= 10;
        }
        if( A <= sum && sum <= B)
        ans += i;
    }

    cout << ans << endl;

    return 0;

}