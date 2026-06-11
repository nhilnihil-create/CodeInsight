#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,c[3][3],a[3],b[3];
    bool flag =true;
    

    rep(i, 3){
        rep(j,3){
            cin >> c[i][j];
        }
    }

    for(int k = -100;k<=100;k++){
        a[0] = k;
        b[0] = c[0][0]-k;

        for(int i = 1;i < 3;i++){
            a[i] = c[i][0]-b[0];
        }

        
        for(int j = 1;j <3;j++){
            b[j] = c[0][j]-a[0];
        }

        for(int i = 1;i < 3;i++){
            for(int j = 1;j < 3;j++){
                if(a[i]+b[j] != c[i][j]){
                    flag = false;
                }
            }
        }
    }

    if(flag)
        cout << "Yes" << endl;

    else
        cout << "No" << endl;

    return 0;
}