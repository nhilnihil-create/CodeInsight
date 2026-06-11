#include <bits/stdc++.h>
using namespace std;

int factor_2(int x){
    int res = 0;
    while(x > 0){
        if(x % 2 == 0){
            res++;
            x /= 2;
        }else{
            return res;
        }
    }
    return res;
}
int main()
{
    bool flag = false;
    int cnt = 0;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cnt += factor_2(a[i]);
    }

    cout << cnt << endl;

}