#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,count=0;
    cin >> n;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin >> a.at(i);
    }
    for(i=0;i<n-1;i++){
        if(a.at(i)==a.at(i+1)){a.at(i+1)=0;count++;}
    }
    cout << count << endl;
    return 0;
}