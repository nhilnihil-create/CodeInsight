#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int A,B,C,cnt;
    cin >> A >> B >> C;
    cnt = 0;
    while(true){
        if(cnt >= C || B < A){
            break;
        }
        cnt++;
        B-=A;
    }
    cout << cnt << endl;
}
