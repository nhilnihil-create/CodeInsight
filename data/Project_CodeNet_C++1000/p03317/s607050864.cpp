#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,i,count=0,tmp=0;
    cin >> n >> k;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin >> a.at(i);
    }
    for(i=0;;i++){
        if(i==0){count++;tmp+=k;}
        else {count++;tmp+=k-1;}
        if(tmp>=n)break;
    }
    cout << count << endl;
    return 0;
}