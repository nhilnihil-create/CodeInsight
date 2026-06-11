#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
    int N, x;
    int c = 0;
    int a[110];
    cin >> N >> x;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a,a+N);
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += a[i];
        if(sum > x) break;
        c++;
    }

    if(sum >= x) cout << c << endl;
    else cout << c - 1 << endl;

    return 0;
}