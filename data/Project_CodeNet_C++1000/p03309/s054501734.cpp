#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calc(int b, vector<int> a){
    long long sum = 0;
    for(int i = 0; i < a.size(); ++i){
        sum += abs(a[i] - b);
    }
    return sum;
}
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] -= i+1;
    }
    int b;
    sort(a.begin(),a.end());
    if(n%2 == 0) b = a[n/2 -1];
    else b = a[n/2];
    cout << calc(b,a) << endl;
    return 0;
}
//Saw the solution video