#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,n,max=0,sum=0;
    cin >> n;
    vector<int> l(n);
    for(i=0;i<n;i++){
        cin >> l.at(i);
        sum += l.at(i);
        if(i==0)max=l.at(i);
        if(max<l.at(i))max=l.at(i);
    }
    if(sum-max>max)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}