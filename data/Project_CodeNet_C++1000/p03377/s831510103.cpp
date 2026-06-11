#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
    int a,b,x;
    cin >> a >> b >> x;
    if(x>=a){
        if(b>=x-a){
            cout << "YES" << endl;
        }

    else cout << "NO" << endl;
    }
    
    else cout << "NO" << endl;
}
