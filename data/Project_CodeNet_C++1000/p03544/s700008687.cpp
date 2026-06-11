#include <bits/stdc++.h>
using namespace std;

uint64_t l[87];
int main(){
    l[0] = 2;
    l[1] = 1;

    for(int i=2; i<=86; i++){
        l[i] = l[i-1] + l[i-2];
    }

    int x;
    cin >> x;
    cout << l[x] << endl;


}
