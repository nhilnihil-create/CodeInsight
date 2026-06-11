#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int now = a[0];
    int cou = 0;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == now){
            cou++;
        }else{
            now = a[i];
            if(cou != 0){
                if(cou % 2 == 0){
                    ans += (cou / 2);
                }else{
                    ans += (cou / 2);
                    ans++;
                }
            }
            cou = 0;
        }
    }

    if(cou != 0){
        if(cou % 2 == 0){
            ans += (cou / 2);
        }else{
            ans += (cou / 2);
            ans++;
        }
    }

    cout << ans << endl;
}