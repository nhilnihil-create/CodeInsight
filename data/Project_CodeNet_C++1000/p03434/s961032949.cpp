#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int>a(n);
    int i;
    for(i = 0;i < n;i++){
        cin >> a.at(i);
    }
    for(i = 0;i < n-1;i++){
        int j;
        for(j = n-1;j > i;j--){
            if(a.at(j) > a.at(j-1)){
                int tmp;
                tmp = a.at(j);
                a.at(j) = a.at(j-1);
                a.at(j-1) = tmp;
            }
        }
    }

    int alice = 0;
    int bob = 0;
    for(i = 0;i < n;i+=2){
        alice += a.at(i);
    }
    for(i = 1;i < n;i+=2){
        bob += a.at(i);
    }

    cout << (alice - bob) << endl;
}