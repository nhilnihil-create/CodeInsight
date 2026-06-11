#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    sort(l.begin(), l.end());
    int sum = 0; for(int i= 0; i < n-1; i++) sum += l[i];
    if(l[n-1] < sum) puts("Yes");
    else puts("No");
    return 0;
}
