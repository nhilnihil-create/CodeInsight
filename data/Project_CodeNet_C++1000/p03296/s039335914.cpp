#include <bits/stdc++.h>

using namespace std;

long long n, a[105], k;

int main() {

cin >> n;

for (int i = 1; i <= n; ++i){
    cin >> a[i];
}


for (int i = 1; i < n; ++i){
    if (a[i] == a[i + 1]){
        if (a[i + 1] == a[i + 2]) {a[i + 1] = k * -1; k++;}
        else {k++;}
    }
}

cout << k;

return 0;

}
