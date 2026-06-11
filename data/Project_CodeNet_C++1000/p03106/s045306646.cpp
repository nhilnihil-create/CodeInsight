#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int a,b,k;
    cin >> a >> b >> k;
    if(a>b) swap(a,b);

    vector<int> cm;
    for(int i=a;i>=1;i--){
        if(a%i==0 && b%i==0) cm.push_back(i);
    }
    cout << cm[k-1] << endl;
    return 0;
}