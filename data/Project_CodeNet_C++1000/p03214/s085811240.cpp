#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    double a[n], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    double mi = 100,ave = sum/n;
    int ind;
    for(int i = 0; i < n; i++){
        if(mi > abs(a[i]-ave)){
            mi = abs(a[i]-ave); ind = i;
        }
    }
    cout << ind <<endl;
    return 0;
}