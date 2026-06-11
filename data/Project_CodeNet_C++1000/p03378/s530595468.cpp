#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n+1, 0);
    for(int i = 0; i < m; i++){
        int a0;
        cin >> a0;
        a[a0] = 1;
    }

    int toright = 0;
    for(int i = x; i <= n; i++) toright += a[i];
    int toleft = 0;
    for(int i = x; i >= 0; i--) toleft += a[i];

    if(toright < toleft) cout << toright << endl;
    else cout << toleft << endl;
    return 0;
}