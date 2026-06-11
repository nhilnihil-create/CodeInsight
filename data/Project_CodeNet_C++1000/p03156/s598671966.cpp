#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,a,b;
    cin >> n >> a >> b;
    int p[n],num[3] = {};
    for(int i = 0;i < n;i++)cin >> p[i];
    for(int i = 0;i < n;i++){
        if(p[i] >= b+1)num[1]++;
        else if(p[i] >= a+1 && p[i] <= b)num[2]++;
        else num[0]++;
    }
    sort(num,num+3);
    cout << num[0];
}