#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==3){
        cout << 2 << ' ' << 5 << ' ' << 63 << endl;
        return 0;
    }
    else if(n==4){
        cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63 << endl;
        return 0;
    }
    vector<long long> ans;
    for(int i=0; i<n/8; i++){
        ans.push_back(2+i*12);
        ans.push_back(3+i*12);
        ans.push_back(4+i*12);
        ans.push_back(6+i*12);
        ans.push_back(8+i*12);
        ans.push_back(9+i*12);
        ans.push_back(10+i*12);
        ans.push_back(12+i*12);
    }
    int m = n%8;
    int k = n/8;
    if(m!=0){
        ans.push_back(6+k*12);
        if(m%2==0) ans.push_back(12+k*12);
        m = (m-1)/2;
        if(m > 0) {
            ans.push_back(2+k*12);
            ans.push_back(4+k*12);
            m--;
        }
        if(m > 0) {
            ans.push_back(3+k*12);
            ans.push_back(9+k*12);
            m--;
        }
        if(m > 0) {
            ans.push_back(8+k*12);
            ans.push_back(10+k*12);
            m--;
        }
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
