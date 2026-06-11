#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int mini = -1, maxi = -1;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a > maxi || maxi == -1) maxi = a;
        if(a < mini || mini == -1) mini = a;
    }
    cout << maxi - mini << endl;
}