#include<bits/stdc++.h>
using namespace std;
int N, A, B;
vector<int> ans;

int main(){
    cin >> N >> A >> B;
    if((N - 1) / A + 1 > B || B > N - A + 1){
        cout << -1 << endl;
        return 0;
    }

    int len = 1;
    int num = N - A + 1;
    for(int i = 0; i < A; i++){
        cout << num + i << " ";
    }
    while(len + num - A > B){
        num -= A;
        for(int i = 0; i < A; i++){
            cout << num + i << " ";
        }
        len++;
    }
    for(int i = B - len; i < num && i > 0; i++){
        cout << i << " ";
    }
    for(int i = B - len - 1; i  > 0; i--){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}