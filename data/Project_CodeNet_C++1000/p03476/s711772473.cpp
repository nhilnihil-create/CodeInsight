#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> p(100001, 1);
    p[0] = 0;
    p[1] = 0;
    for(int i = 2; i <= 100000; i++){
        if(p[i]){
            int j = 2*i;
            while(j <= 100000){
                p[j] = 0;
                j += i;
            }
        }
    }

    vector<int> sum(100001);
    for(int i = 1; i <= 100000; i++){
        if(p[i] == 1 && p[(i+1)/2] == 1 && i % 2 == 1) sum[i] += sum[i-1] + 1;
        else sum[i] = sum[i-1];
    }

    /*for(int i = 0; i < 10; i++){
        if(p[i]) cout << i << ' ';
    }
    cout << endl;*/

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << endl;
    }
}