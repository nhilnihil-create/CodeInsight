#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    vector<int> A(3);
    for(int i=0; i<3; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    int x,y;
    x=A.at(2)-A.at(0);
    y=A.at(2)-A.at(1);
    if(x%2==0 && y%2 ==0){
        cout << (x+y)/2 << endl;
    }
    else if(x%2==1 && y%2==1){
        cout << (x+y)/2 << endl;
    }
    else{
        cout << (x+y)/2 + 2 << endl;
    }
}