#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> l(3);
    for(int i=0;i<3;i++){
        cin >> l.at(i);
    }
    sort(l.begin(),l.end());
    int x=l.at(2)-l.at(1)+(l.at(1)-l.at(0))/2;
    if((l[1]-l[0])%2==0){
        cout << x << endl;
    }
    else{
        cout << x+2 << endl;
    }
}