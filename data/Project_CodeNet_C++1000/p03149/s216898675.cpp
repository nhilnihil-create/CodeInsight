#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> n(10);
    for(int i=0;i<4;i++){
        int a;
        cin >> a;
        n.at(a)++;
    }
    if(n.at(1)==1&&n.at(7)==1&&n.at(9)==1&&n.at(4)==1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}