#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int A, min_cnt, cnt = 0;
    cin >> A;

    while(A % 2 == 0){
        cnt++;
        A /= 2;
    }

    min_cnt = cnt;
    
    for(int i = 0; i < N-1; i++){
        cnt = 0;
        cin >> A;
        while(A % 2 == 0){
            cnt++;
            A /= 2;
        }
        if(cnt < min_cnt) min_cnt = cnt;
    }

    cout << min_cnt << endl;
}
