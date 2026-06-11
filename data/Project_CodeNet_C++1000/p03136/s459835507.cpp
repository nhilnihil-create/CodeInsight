#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> l(n);
    int maxv = 0;
    for(int i=0; i<n; i++){
        cin >> l.at(i);
        if(maxv < l.at(i)){
            maxv = l.at(i);
        }
    }
    if(maxv < accumulate(l.begin(),l.end(),0)-maxv){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}