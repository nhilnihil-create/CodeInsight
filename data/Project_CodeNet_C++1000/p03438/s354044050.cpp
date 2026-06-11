#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long alla = 0,allb = 0,ope = 0;
    vector<long long> a(n),b(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        alla += a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
        allb += b[i];
        if(a[i] < b[i])ope += (b[i] - a[i] + 1) / 2;

    }
    if((allb - alla) < ope)cout << "No" << endl;
    else cout << "Yes" << endl;
}
