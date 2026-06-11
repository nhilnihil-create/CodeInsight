#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    int N;
    bool flag = false;
    cin >> N;

    for(int a = 0;4*a <= N;a++){
        int b = N-4*a;

        if(b%7 == 0){
            flag = true;
            break;
        }

    }
    
    if(flag)
        cout << "Yes" << endl;

    else
        cout << "No" << endl;
    return 0;
}