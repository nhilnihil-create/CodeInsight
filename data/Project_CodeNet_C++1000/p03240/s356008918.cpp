#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long x[n], y[n], z[n];
    int base = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
        if(z[i]) base = i;
    }
    for(int i = 0; i <= 100; i++){
        for(int j = 0;  j<= 100; j++){
                long long h = abs(i - x[base]) + abs(j - y[base]) + z[base];
                int f = 0;
                for(int k = 0; k < n; k++){
                    long long hh = h - (abs(i - x[k]) + abs(j - y[k]));
                    hh = max(hh, 0ll);
                    if(hh != z[k]) {
                        f = 1; break;
                    }
                }
                if(!f){
                    cout << i << " " << j << " " << h << endl;
                    return 0;
                }

        }
    }
}
