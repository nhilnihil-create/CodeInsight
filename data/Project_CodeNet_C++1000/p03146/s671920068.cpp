#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#include <string>

int main(){
    int s;cin >> s;
    int arr[1000000];
    int ex;
    int cnt = 0;
    bool isEnd = false;
    for(int i=1;i<=1000000;i++){
        if(i==1){
            ex = s;
        }else if(ex%2==0){
            ex = ex/2;
        }else{
            ex = 3*ex+1;
        }
        //cout << ex << endl;
        for(int j=0;j<cnt;j++){
            
            if(arr[j] == ex){
                //printf("-------------------------\n");
                cout << cnt+1 << endl;
                isEnd = true;
                break;
            }
        }
        arr[cnt] = ex;
        cnt++;
        if(isEnd) break;

    }



}