#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int x;
    cin >> x;
    vector<int> a(x+1);
    if(x==1)cout << 1 << endl;
    else{
    for(int i=2;i<=x;i++){
        int num1=i;
        int num2=i;
        while(num1*num2<=x){
            num1=num1*num2;
            a.at(num1)++;
        }
    }
    for(int i=x;i>=0;i--){
        if(a.at(i)>0){
            cout << i << endl;
            break;
        }
    }
    }
}
