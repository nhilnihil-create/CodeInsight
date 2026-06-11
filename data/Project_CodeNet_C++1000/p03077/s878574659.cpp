#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    long long N;
    cin >> N;
    long long min_num = 2000000000000000;
    for(int i=0;i<5;i++){
        long long num;
        cin >> num;
        min_num = min(min_num,num);
    }
    long long ans = (N + min_num - 1) / min_num + 4;
    cout << ans << endl;
}
