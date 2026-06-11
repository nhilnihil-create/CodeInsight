#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    int cou_1 = 0;
    int cou_2 = 0;
    int cou_3 = 0;
    for(int i = 0; i < n; i++){
        if(p[i] <= a){
            cou_1++;
        }else if(p[i] > b){
            cou_3++;
        }else{
            cou_2++;
        }
    }

    int ans = cou_1;
    if(ans > cou_2){
        ans = cou_2;
    }
    if(ans > cou_3){
        ans = cou_3;
    }

    cout << ans << endl;
}