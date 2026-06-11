#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int min_ol = 1009, sum_ol = 0;
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        min_ol = min(min_ol, m);
        sum_ol+= m;
    }
    int count = 0;
    x -= sum_ol;
    while(x >= min_ol){
        x -= min_ol;
        count++;
    }
    cout << count + n << '\n';
    return 0;
}