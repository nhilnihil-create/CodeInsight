#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n;
    cin >> n;
    int m = 0;
    int l = 0;
    for(int i = 1; i <= n; i += 2){
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                m++;
            }
        }
        if(m == 8){
            l++;
        }
        m = 0;
    }
    cout << l << endl;
}
