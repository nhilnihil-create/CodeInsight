#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int r;
    
    cin >> r;
    
    if(r  <  1200){
        cout<<"ABC"<<"\n";
    }
    else if(r >= 1200 && r < 2800){
        cout << "ARC"<< "\n";
    }
    else{
        cout<<"AGC" <<"\n";
    }
    return 0;
}