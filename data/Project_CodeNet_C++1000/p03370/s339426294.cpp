#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, X;
    cin >> N >> X;
    int m[N];

    for(int i = 0; i < N; i++){
        cin >> m[i];
    }

    int min = 0;
    int minm = 114514;
    for(int i = 0; i < N; i++){
        min += m[i];
        if(minm > m[i]) minm = m[i];
    }

    int ans = (X-min) / minm;

    cout << N + ans << endl;
}