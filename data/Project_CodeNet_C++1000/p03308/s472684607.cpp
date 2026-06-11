#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int minnum = 1001001001;
    int maxnum = -1;
    for(int i = 0; i < n; i++){
        if(a[i] > maxnum) maxnum = a[i];
        if(a[i] < minnum) minnum = a[i];
    }

    cout << maxnum-minnum << endl;
    return 0;
}