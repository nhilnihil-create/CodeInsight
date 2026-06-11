/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+5;

int a[3];

int main(){
    cin >> a[0] >> a[1] >> a[2];
    sort(a , a + 3);
    if(a[0] == a[1]){
        cout << a[2];
    } else {
        cout << a[0];
    }
}



