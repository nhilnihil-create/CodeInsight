#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;

    int a[m];
    int y[n-1];


    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a, a+m);

    for(int i = 0; i < n-1; i++){
        y[i] = 0;
    }

    for(int i = 0; i < m-1; i ++){
        y[i] = abs(a[i+1] - a[i]);
    }

    sort(y, y+m-1);
    int all = 0;

    for(int i = 0; i < m - 1 - (n - 1); i++){
        all += y[i];
    }
    cout << all << endl;
}