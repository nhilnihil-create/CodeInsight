#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, q, l, r;
    string s;
    cin >> n >> q >> s;
    vector<int>a(n);

    for(int i=1; i<s.size(); i++){
        if(s[i]=='C'&&s[i-1]=='A'){
            a[i] = a[i-1]+1;
        }else{
            a[i] = a[i-1];
        }
    }

    for(int i=0; i<q; i++){
        cin >> l >> r;
        l--; r--;
        cout << a[r]-a[l] << endl;
    }
    return 0;
}