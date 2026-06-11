#include<bits/stdc++.h>
using namespace std;

int n, m, c;
vector<int> b;
int res;

int main(void){
    cin >> n >> m >> c;
    b = vector<int>(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    res = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            sum += a*b[j];
        }
        if(sum + c > 0) res++;
    }
    cout << res << endl;
    return 0;
}
