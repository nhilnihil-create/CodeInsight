#include <iostream>
#include <cstdio>
using namespace std;

int n, c[500], s[500], f[500];

int main(){
    cin >> n;

    for(int i = 1; i < n; i++){
        cin >> c[i] >> s[i] >> f[i];
    }

    for(int i = 1; i <= n; i++){
        int t = 0;
        for(int j = i; j < n; j++){
            if(t < s[j]){
                t = s[j];
            }
            else{
                if(t % f[j] != 0){
                    t += f[j] - t%f[j];
                }
            }
            t += c[j];
        }
        printf("%d\n", t);
    }

    return 0;
}