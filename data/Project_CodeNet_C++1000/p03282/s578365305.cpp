#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    long long k;
    cin >> s;
    cin >> k;
    k--;
    int res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1'){
            res = i;
            break;
        }
    }

    if(res<=k){
        cout << s[res] << endl;
    }else{
        cout << 1 << endl;
    }
}