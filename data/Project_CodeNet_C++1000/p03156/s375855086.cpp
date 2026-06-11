#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    int s=0, t=0, u=0;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p <= A) s++;
        else if (p <= B) t++;
        else u++;
    }
    cout << min(min(s, t), u) << endl;
    return 0;
}