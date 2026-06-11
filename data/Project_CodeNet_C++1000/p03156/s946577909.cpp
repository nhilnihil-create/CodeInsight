#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:
wa:
反省:
考察:
*/
int main() {
    int N;
    cin >> N;
    int a, b;
    cin >> a >> b;
    int p[110];
    int ans;
    int q1 = 0;
    int q2 = 0;
    int q3 = 0;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < N; i++){
        if(p[i] <= a) q1++;
        else if(a+1 <= p[i] && p[i] <= b) q2++;
        else q3++;
    }
    ans = min(min(q1, q2),q3);
    cout << ans << endl;
    return 0;
}