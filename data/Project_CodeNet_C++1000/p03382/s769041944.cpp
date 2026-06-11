#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max = 0;
    int maxn = 0;
    for(int i = 0; i < n; i++){
        if(max < a[i]) {
            max = a[i];
            maxn = i;
        }
    }
    double s = max/2.0;
    double d = s;
    int j;
    for(int i = 0; i < n; i++){
        if(i == maxn) continue;
        double f = fabs(s - a[i]);
        if(f <= d) {
             d = f;
             j = i;
        }
    }
    cout << max << " " << a[j] << endl;

    return 0;
}