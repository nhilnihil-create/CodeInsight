#include<iostream>
using namespace std;
int main(){
    int n,a;
    cin >> n >> a;
    int m = n % 500;
    bool flag = false;
    if(m != 0){
        int k = n / 500; //500円を何枚使うか
        n -= k * 500;
        for(int i = 0; i <= a; i++){
            if(i == n){
                flag = true;
            }
        }
    }
    else{
        flag = true;
    }
    cout << (flag ? "Yes" : "No") << endl;
}
