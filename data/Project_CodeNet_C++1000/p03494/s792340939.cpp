#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,count = 0;
    int A[200];
    bool flag = true;

    cin >> N;

    for(int i = 0;i < N;i++)
    scanf("%d",&A[i]);
    
    while(true){
        for(int i = 0;i < N;i++){
            if(A[i]%2 != 0){
                flag = false;
                break;
            }
        }

        if(flag == false)
        break;

        for(int i = 0;i < N;i++){
            A[i] /= 2;
        }

        count++;
    }

    cout << count << endl;
    return 0;
}