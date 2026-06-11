#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;

    int max_num = 1;
    for(int i=1; i<=N; i++) max_num *= 3;

    int temp, buf = 1;
    for(int i=0; i<N; i++){
        cin >> temp;

        if(temp%2 == 0) buf *= 2;
    }

    cout << max_num - buf << endl;
    return 0;
}
