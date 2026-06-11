#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N,max=0;
    cin >> N;
    int data[2][N];
    
    for(int i=0;i<N;i++) cin >> data[0][i];
    for(int i=0;i<N;i++) cin >> data[1][i];
    
    for(int i=0;i<N;i++){
        int num = 0;
        int key = 0;
        bool flag = true;
        for(int j=0;j<N;j++){
            num += data[key][j];
            if(j == i && flag){
                key++;
                j--;
                flag = false;
            }
        }
        if(max < num) max = num;
    }
    cout << max << endl;
}