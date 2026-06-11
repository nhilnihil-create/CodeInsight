#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    int maxx = 1;
    for(int i=2;i<=100;i++){
        int tmp = i*i;
        while(tmp<=x){
            maxx = max(tmp,maxx);
            tmp *= i;
        }
    }
    cout << maxx << endl;
}