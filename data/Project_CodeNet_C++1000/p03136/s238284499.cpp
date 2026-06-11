#include <bits/stdc++.h>
using namespace std;


int main() {

 
    int n;
    cin>>n;

    vector<int> L(n);
    for(int i=0;i<n;i++){
        cin>>L.at(i);
    }

    sort(L.begin(),L.end());

    int L_longest=L.at(n-1);
    int L_sum=0;
    for(int i=0;i<n-1;i++){
        L_sum+=L.at(i);
    }

    if(L_longest<L_sum)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}