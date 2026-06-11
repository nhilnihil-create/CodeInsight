#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i=0; i<n-1; i++){
        sum += abs(a[i+1]-a[i]);
    }
    sum += abs(a[0])+abs(a[n-1]);
    int sum1 = sum;
    for(int i=0; i<n; i++){
        if(i==0){
            sum -= abs(a[0])+abs(a[1]-a[0]);
            sum += abs(a[1]);
            cout << sum << endl;
            sum = sum1;
            continue;
        }
        if(i==n-1){
            sum -= abs(a[n-2]-a[n-1])+abs(a[n-1]);
            sum += abs(a[n-2]);
            cout << sum << endl;
            sum = sum1;
            continue;
        }
        sum -= abs(a[i]-a[i-1])+abs(a[i]-a[i+1]);
        sum += abs(a[i-1]-a[i+1]);
        cout << sum << endl;
        sum = sum1;
    }
    return 0;
}