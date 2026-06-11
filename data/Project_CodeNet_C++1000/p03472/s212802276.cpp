#include<iostream>
#include<algorithm>
using namespace std;

int atk[100005], datk[100005];

int main() { 
    int N, H, cnt = 0, maks = 0;
    cin >> N >> H;
    for(int i=1; i<=N; i++){
        cin >> atk[i] >> datk[i];
        if(atk[i] > maks){
            maks = atk[i];
        }
    }
    sort(datk, datk + N);
    for(int i=N; i>=1; i--){
        if(datk[i] > maks){
            cnt++;
            H-= datk[i];
            if(H <= 0) break;
        }
    }

    if(H < 0){
        cout << cnt << endl;
    } else if(H % maks == 0){
        cout << cnt + H/maks << endl;
    } else{
        cout << cnt + H/maks + 1 << endl;
    }
}