#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)

int diffplus(int n){
    int sum = 0; 
    while (n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main(void){
    int n;
    cin >> n;
    int j = 0,sum = 1000000;
    int temp = 0;
    rep(i,n){
        j = n - i;
        int a = diffplus(i);
        int b = diffplus(j);
        temp =  a+b;
        if(sum > temp) sum = temp;          
    }
    cout << sum << endl;

}