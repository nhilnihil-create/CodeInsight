#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string num;
    cin >> num;

    if(num.size() == 1){
        cout << num[0] << endl;
        return 0;
    }

    int top = (int)(num[0] - '0') - 1;

    int under;
    for(int i=1; i<num.size(); i++){
        if(num[i] != '9'){
            under = (num.size()-1)*9;
            cout << top + under << endl;
            return 0;
        }
    }
    under = (num.size()-1)*9;
    cout << top + under + 1 << endl;
    return 0;
    
}