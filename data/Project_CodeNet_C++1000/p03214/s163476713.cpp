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
    int n;
    cin >> n;
    vector <double> a(n);
    double sum = 0;
    int min_n = 110;
    double min = 110;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double ave = sum/(double)n;
    for(int i = 0; i < n; i++){
        double a_p = ((a[i]-ave) > 0) ? (a[i]-ave) : (ave-a[i]);
        if(min > a_p){
            min = a_p;
            min_n = i;
        }
    }
    cout << min_n << endl;
    return 0;
}