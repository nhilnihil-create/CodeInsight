#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, x, count = 0;
    cin >> N >> x;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a, a + N);
    int i = 0;
    for(i = 0; i < N - 1; i++){
        x -= a[i];
        if(x < 0) break;
        count++;
    }
    if(x == a[i]){
        count++;
    }

    cout << count << endl;
}