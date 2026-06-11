#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;

    int k;
    cin >> k;

    int flag = 0;
    for(int i = 0; i < k; i++){
        if(flag == 0){
            if(a % 2 == 1){
                a--;
            }

            b += (a / 2);
            a /= 2;
            flag = 1;
        }else{
            if(b % 2 == 1){
                b--;
            }

            a += (b / 2);
            b /= 2;
            flag = 0;
        }
    }

    cout << a << " " << b << endl;
}