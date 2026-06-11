#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> array(n);
    int cnt = 0;
    for(int i=1;i<n;i++){
        if(s.at(i-1) == 'A' && s.at(i) == 'C'){
            array.at(i) = array.at(i-1)+1;
        }else{
            array.at(i) = array.at(i-1);
        }
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << array.at(r-1) - array.at(l-1) << endl;
    }
}