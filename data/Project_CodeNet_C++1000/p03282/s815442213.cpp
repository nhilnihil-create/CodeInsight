#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        if(s.at(i) != '1'){
            cout << s.at(i) << endl;
            return 0;
        }
        if(i==k-1){
            cout << '1' << endl;
        }
    }
}