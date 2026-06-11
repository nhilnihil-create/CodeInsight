#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int divide_times(int n){
    int divided = 0;
    while(n){
        if(n % 2 == 0){
            divided++;
            n /= 2;
        }else{
            break;
        }
    }
    return divided;
}

int main(){
    int N, A;
    cin >> N;
    int min = 1000000000;

    rep(i, N)
    {
        cin >> A;
        int divided = divide_times(A);
        if (min > divided) min = divided;
    }

    cout << min << endl;

    return 0;
}