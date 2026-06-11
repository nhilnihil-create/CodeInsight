#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int a,b,c,x;
    cin >> a >> b >> c >> x;
    int count =0;
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            for(int k=0; k<=c; k++){
                int num = i*500 + j*100 + k*50;
                if(num==x){
                    count++;
                }
            }
        }
    }
    cout << count <<endl;
}