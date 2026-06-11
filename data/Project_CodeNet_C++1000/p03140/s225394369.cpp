#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;string a,b,c;
    cin >> n >> a >> b >> c;
    int sum = 0;
    for(int i = 0;i < n;i++){
        int num = 0;
        if(a[i] == b[i])num++;
        if(a[i] == c[i])num++;
        if(b[i] == c[i])num++;
        if(num < 3)sum += 2-num;
    }
    cout << sum << endl;
}