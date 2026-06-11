#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n, a[100000], b;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    b = a[0];
    for(int i=1;i<n-1;i++){
        if(abs(a[i]-a[n-1]/2) <= abs(b-a[n-1]/2))b = a[i];
    }
    cout << a[n-1] << " " << b << endl;
}
