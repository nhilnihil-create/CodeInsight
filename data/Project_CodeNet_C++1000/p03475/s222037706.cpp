#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 500;
int c[MAX], s[MAX], f[MAX];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> c[i] >> s[i] >> f[i];
    }
    for(int i = 0; i < n-1; i++){
        int t = s[i] + c[i];
        for(int j = i+1; j < n-1; j++){
            if(t >= s[j]){
                t = (t + f[j] - 1) / f[j] * f[j];
            } else {
                t = s[j];
            }
            t += c[j];
        }
        cout << t << endl;
    }
    cout << 0 << endl;
    return 0;
}