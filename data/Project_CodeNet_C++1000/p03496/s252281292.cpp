#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, a[100], path[110][2], max, min;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    for(int i=0;i<110;++i){
        for(int j=0;j<2;++j){
            path[i][j] = 0;
        }
    }
    max = a[0];
    min = a[0];
    int map = 0, mip = 0, cnt=0;
    for(int i=0;i<n;++i){
        if(max < a[i]){
            max = a[i];
            map = i;
        }
        if(min > a[i]){
            min = a[i];
            mip = i;
        }
    }
    if(abs(max) >= abs(min)){
        for(int i=0;i<n;++i){
            path[cnt][0] = map+1;
            path[cnt][1] = i+1;
            ++cnt;
            a[i] += a[map];
        }
        for(int i=1;i<n;++i){
            if(a[i] < a[i-1]){
                path[cnt][0] = i;
                path[cnt][1] = i + 1;
                ++cnt;
                a[i] += a[i-1];
            }
        }
    }else{
        for(int i=0;i<n;++i){
            path[cnt][0] = mip+1;
            path[cnt][1] = i+1;
            ++cnt;
            a[i] += a[mip];
        }
        for(int i=n-2;i>=0;--i){
            if(a[i] > a[i+1]){
                path[cnt][0] = i+2;
                path[cnt][1] = i+1;
                ++cnt;
                a[i] += a[i+1];
            }
        }
    }
    cout << cnt << endl;
    for(int i=0;i<cnt;++i){
        cout << path[i][0] << " " << path[i][1] << endl;
    }
}