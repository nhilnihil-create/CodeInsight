#include <iostream>
#include<vector>
using namespace std;
int main(void){
    int n,m,x;
    cin >> n >> m >> x;
    vector<int>a(m);
    vector<int>f(n + 1);
    for(int i = 0;i < m;i++){
        cin >> a[i];
        f[a[i]]++;
    }
    for(int i = 1;i <= n;i++){
        f[i] += f[i - 1];
    }
    cout << min(f[x],f[n] - f[x]) << endl;
}
