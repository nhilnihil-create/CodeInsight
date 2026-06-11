#include <bits/stdc++.h>
using namespace std;


/*
int calc(int x){
    int ret = 0;
    while(x % 100 == 0){
        x = x/100;
        ++ret;
    }
    return ret;
}

int main(){
    int D, N;
    cin >> D >> N;
    int cnt=0, val = 0;
    while (cnt<N){
        ++val;
        if(calc(val) == D){
            ++cnt;
        }
    }
    cout << val << endl;
}
*/

int main(){
    int d,n; cin >> d >> n;
    if(d == 0){
        cout << n+n/100 << endl;
    }else if(d == 1){
        cout << (n+n/100)*100 << endl;
    }else{
        cout << (n+n/100)*10000 << endl;
    }
}