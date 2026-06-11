#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    int mini = -1, maxi = -1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] > maxi || maxi == -1) maxi = a[i];
        if(a[i] < mini || mini == -1) mini = a[i];
    }
    cout << maxi - mini << endl;
}