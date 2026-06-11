#include <iostream>
using namespace std;
int main(){
    string s; int k, cnt=0;
    cin >> s >> k;
    for(int i=0; i<k; i++){
        if(s[i]!='1'){
            cout << s[i] << endl;
            return 0;
        }else{
            cnt++;
        }
    }
    if(cnt==k) cout << 1 << endl;
    return 0;
}