#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int N, x;
    cin >> N >> x;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    sort(a, a+N, less<int>());

    int sum = 0;
    int index = 0;
    for(int i = 0; i < N; i++){
        sum += a[i];
        if(sum > x) break;
        index++;
    }

    bool flag = true;
    if((sum < x) && (index == N)) flag = false;

    if(flag) cout << index << endl;
    else cout << N-1 << endl;
}